#include "PulseOximeterMonitor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <thread>
#include <random>
#include <ctime>

// Logger
Logger::Logger(const std::string& path) : ofs_(path, std::ios::app) {}

void Logger::log(const std::string& entry)
{
    if (!ofs_) return;
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    ofs_ << std::put_time(std::localtime(&t), "%F %T") << " " << entry << "\n";
    ofs_.flush();
}

// MockSensor
MockSensor::MockSensor()
  : rng_(std::random_device{}()),
    spo2Dist_(85, 104),
    tempDeciDist_(350, 740)
{

}

VitalSigns MockSensor::read()
{
    VitalSigns v;
    v.spo2 = spo2Dist_(rng_);
    v.tempC = tempDeciDist_(rng_) / 10.0;
    return v;
}

// AlarmPolicy
AlarmPolicy::AlarmPolicy(int spo2Th, double tempTh) : spo2Th_(spo2Th), tempTh_(tempTh)
{

}

bool AlarmPolicy::lowSpO2(int spo2) const
{
	return spo2 < spo2Th_;
}

bool AlarmPolicy::highTemp(double t) const
{
	return t > tempTh_;
}

// AlarmManager
AlarmManager::AlarmManager(const AlarmPolicy& policy, Logger& logger, const std::string& serverPath)
  : policy_(policy), logger_(logger), serverPath_(serverPath)
{

}
bool AlarmManager::evaluateAndHandle(const std::string& patientId, const std::string& patientName, const VitalSigns& v)
{
    bool escalated = false;
    if (policy_.lowSpO2(v.spo2))
    {
        std::ostringstream oss;
        oss << "ALARM LOW_SPO2 patient=" << patientId << " name=" << patientName << " spo2=" << v.spo2;
        logger_.log(oss.str());
        std::cout << "Alarm: Low SpO2 for " << patientName << " (" << v.spo2 << "%)\n";

        if (v.spo2 < 80)
        {
            escalate(oss.str());
            escalated = true;
        }
    }
    if (policy_.highTemp(v.tempC))
    {
        std::ostringstream oss;
        oss << "ALARM HIGH_TEMP patient=" << patientId << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
        logger_.log(oss.str());
        std::cout << "Alarm: High Temp for " << patientName << " (" << v.tempC << "C)\n";
    }
    return escalated;
}


void AlarmManager::escalate(const std::string& message) {
    std::ofstream ofs(serverPath_, std::ios::app);
    if (ofs) {
        ofs << message << "\n";
        ofs.flush();
    }
    logger_.log("ESCALATION SENT: " + message);
    std::cout << "Escalation sent to server: " << message << "\n";
}

// Patient
Patient::Patient(std::string id, std::string name, int age) : id_(std::move(id)), name_(std::move(name)), age_(age)
{

}

const std::string& Patient::id() const
{
	return id_;
}

const std::string& Patient::name() const
{
	return name_;
}

int Patient::age() const
{
	return age_;
}

// Monitor
Monitor::Monitor(std::unique_ptr<ISensor> sensor,
        Patient patient,
        AlarmManager& alarmMgr,
        Logger& logger,
        MonitorConfig cfg)
  : sensor_(std::move(sensor)), patient_(std::move(patient)), alarmMgr_(alarmMgr), logger_(logger), cfg_(std::move(cfg))
{

}

void Monitor::run(int iterations)
{
    auto next = std::chrono::steady_clock::now();

    for (int i = 0; i < iterations; ++i)
    {
        next += cfg_.sampleInterval;
        VitalSigns v = sensor_->read();
        logStatus(v);
        bool critical = alarmMgr_.evaluateAndHandle(patient_.id(), patient_.name(), v);
        if (critical)
        {
            logger_.log("Critical condition for patient " + patient_.id());
        }
        std::this_thread::sleep_until(next);
    }
}

void Monitor::logStatus(const VitalSigns& v)
{
    std::ostringstream oss;
    oss << "STATUS patient=" << patient_.id()
        << " spo2=" << v.spo2
        << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
    logger_.log(oss.str());
    std::cout << "Patient " << patient_.name() << " Age:" << patient_.age() << "\n";
    std::cout << "SpO2=" << v.spo2 << "%  Temp=" << v.tempC << "C\n";
}

// main
int main()
{
    MonitorConfig cfg;
    Logger logger(cfg.logPath);
    AlarmPolicy policy(cfg.spo2Threshold, cfg.tempThreshold);
    AlarmManager alarmMgr(policy, logger, cfg.serverLogPath);
    auto sensor = std::make_unique<MockSensor>();
    Patient patient{"P123", "Alice", 45};
    Monitor monitor(std::move(sensor), patient, alarmMgr, logger, cfg);
    monitor.run(20);
    return 0;
}
