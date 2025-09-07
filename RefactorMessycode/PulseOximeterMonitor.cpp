// refactored_monitor.cpp  (requires -std=c++17)
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <sstream>
#include <iomanip>

// Small value object for vital signs
struct VitalSigns {
    int spo2;
    double tempC;
};

// Configuration (immutable for a monitor instance)
struct MonitorConfig {
    int spo2Threshold = 90;
    double tempThreshold = 38.0;
    std::chrono::milliseconds sampleInterval{1000};
    std::string logPath{"monitor.log"};
    std::string serverLogPath{"server.log"};
};

// Simple RAII Logger (writes timestamped entries)
class Logger {
public:
    explicit Logger(const std::string& path) : ofs_(path, std::ios::app) {}
    void log(const std::string& entry) {
        if (!ofs_) return;
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        ofs_ << std::put_time(std::localtime(&t), "%F %T") << " " << entry << "\n";
        ofs_.flush();
    }
private:
    std::ofstream ofs_;
};

// Sensor interface (allows mocking or hardware implementation)
class ISensor {
public:
    virtual VitalSigns read() = 0;
    virtual ~ISensor() = default;
};

// MockSensor simulating hardware (uses random engine)
class MockSensor : public ISensor {
public:
    MockSensor()
      : rng_(std::random_device{}()),
        spo2Dist_(85, 104),
        tempDeciDist_(350, 740) {}

    VitalSigns read() override {
        VitalSigns v;
        v.spo2 = spo2Dist_(rng_);
        v.tempC = tempDeciDist_(rng_) / 10.0;
        return v;
    }
private:
    std::mt19937 rng_;
    std::uniform_int_distribution<int> spo2Dist_;
    std::uniform_int_distribution<int> tempDeciDist_; // tenths of a degree
};

// AlarmPolicy isolates thresholds and decision logic
class AlarmPolicy {
public:
    explicit AlarmPolicy(int spo2Th, double tempTh) : spo2Th_(spo2Th), tempTh_(tempTh) {}
    bool lowSpO2(int spo2) const { return spo2 < spo2Th_; }
    bool highTemp(double t) const { return t > tempTh_; }
private:
    int spo2Th_;
    double tempTh_;
};

// AlarmManager: centralizes reactions to alarm conditions
class AlarmManager {
public:
    AlarmManager(const AlarmPolicy& policy, Logger& logger, const std::string& serverPath)
      : policy_(policy), logger_(logger), serverPath_(serverPath) {}

    // returns true if critical escalation occurred
    bool evaluateAndHandle(const std::string& patientId, const std::string& patientName, const VitalSigns& v) {
        bool escalated = false;
        if (policy_.lowSpO2(v.spo2)) {
            std::ostringstream oss;
            oss << "ALARM LOW_SPO2 patient=" << patientId << " name=" << patientName << " spo2=" << v.spo2;
            logger_.log(oss.str());
            std::cout << "Alarm: Low SpO2 for " << patientName << " (" << v.spo2 << "%)\n";
            if (v.spo2 < 80) {
                escalate(oss.str());
                escalated = true;
            }
        }
        if (policy_.highTemp(v.tempC)) {
            std::ostringstream oss;
            oss << "ALARM HIGH_TEMP patient=" << patientId << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
            logger_.log(oss.str());
            std::cout << "Alarm: High Temp for " << patientName << " (" << v.tempC << "C)\n";
        }
        return escalated;
    }

private:
    void escalate(const std::string& message) {
        // for demo: write to server log (in real device, send over secure channel)
        std::ofstream ofs(serverPath_, std::ios::app);
        if (ofs) {
            ofs << message << "\n";
            ofs.flush();
        }
        logger_.log("ESCALATION SENT: " + message);
        std::cout << "Escalation sent to server: " << message << "\n";
    }

    const AlarmPolicy& policy_;
    Logger& logger_;
    std::string serverPath_;
};

// Patient as a value object using std::string (safe and copyable)
class Patient {
public:
    Patient(std::string id, std::string name, int age) : id_(std::move(id)), name_(std::move(name)), age_(age) {}
    const std::string& id() const { return id_; }
    const std::string& name() const { return name_; }
    int age() const { return age_; }
private:
    std::string id_;
    std::string name_;
    int age_;
};

// Monitor coordinates reading, logging, alarm checks. Uses dependency injection for sensor/logger/alarm.
class Monitor {
public:
    Monitor(std::unique_ptr<ISensor> sensor,
            Patient patient,
            AlarmManager& alarmMgr,
            Logger& logger,
            MonitorConfig cfg)
      : sensor_(std::move(sensor)), patient_(std::move(patient)), alarmMgr_(alarmMgr), logger_(logger), cfg_(std::move(cfg)) {}

    // run N iterations (makes testing/demos deterministic); production would run until stopped
    void run(int iterations = 20) {
        auto next = std::chrono::steady_clock::now();
        for (int i = 0; i < iterations; ++i) {
            next += cfg_.sampleInterval;
            VitalSigns v = sensor_->read();
            logStatus(v);
            bool critical = alarmMgr_.evaluateAndHandle(patient_.id(), patient_.name(), v);
            if (critical) {
                logger_.log("Critical condition for patient " + patient_.id());
            }
            std::this_thread::sleep_until(next); // steady schedule
        }
    }

private:
    void logStatus(const VitalSigns& v) {
        std::ostringstream oss;
        oss << "STATUS patient=" << patient_.id()
            << " spo2=" << v.spo2
            << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
        logger_.log(oss.str());
        std::cout << "Patient " << patient_.name() << " Age:" << patient_.age() << "\n";
        std::cout << "SpO2=" << v.spo2 << "%  Temp=" << v.tempC << "C\n";
    }

    std::unique_ptr<ISensor> sensor_;
    Patient patient_;
    AlarmManager& alarmMgr_;
    Logger& logger_;
    MonitorConfig cfg_;
};

int main() {
    MonitorConfig cfg; // could be loaded from JSON/config system in real product
    Logger logger(cfg.logPath);
    AlarmPolicy policy(cfg.spo2Threshold, cfg.tempThreshold);
    AlarmManager alarmMgr(policy, logger, cfg.serverLogPath);

    auto sensor = std::make_unique<MockSensor>();
    Patient patient{"P123", "Alice", 45};

    Monitor monitor(std::move(sensor), patient, alarmMgr, logger, cfg);
    monitor.run(20); // run 20 samples for demo
    return 0;
}
