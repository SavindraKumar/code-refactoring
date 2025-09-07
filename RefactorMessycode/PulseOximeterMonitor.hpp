#ifndef PULSE_OXIMETER_MONITOR_HPP
#define PULSE_OXIMETER_MONITOR_HPP

#include <string>
#include <chrono>
#include <memory>
#include <fstream>
#include <random>

/**
 * @brief Value object for vital signs.
 */
struct VitalSigns
{
    int spo2;      ///< Oxygen saturation percentage
    double tempC;  ///< Temperature in Celsius
};

/**
 * @brief Configuration for the monitor (immutable per instance).
 */
struct MonitorConfig
{
    int spo2Threshold = 90;                ///< SpO2 alarm threshold
    double tempThreshold = 38.0;           ///< Temperature alarm threshold
    std::chrono::milliseconds sampleInterval{1000}; ///< Sampling interval
    std::string logPath{"monitor.log"};   ///< Path for local log
    std::string serverLogPath{"server.log"}; ///< Path for server log
};

/**
 * @brief Simple RAII Logger for timestamped entries.
 */
class Logger
{
public:
    /**
     * @brief Construct a logger for a given file path.
     * @param path Log file path
     */
    explicit Logger(const std::string& path);
    /**
     * @brief Log a string entry with timestamp.
     * @param entry Log message
     */
    void log(const std::string& entry);
private:
    std::ofstream ofs_;
};

/**
 * @brief Sensor interface for reading vital signs.
 */
class ISensor
{
public:
    /**
     * @brief Read current vital signs.
     * @return VitalSigns struct
     */
    virtual VitalSigns read() = 0;
    virtual ~ISensor() = default;
};

/**
 * @brief Mock sensor simulating hardware readings.
 */
class MockSensor : public ISensor
{
public:
    MockSensor();
    VitalSigns read() override;
private:
    std::mt19937 rng_;
    std::uniform_int_distribution<int> spo2Dist_;
    std::uniform_int_distribution<int> tempDeciDist_;
};

/**
 * @brief Alarm policy for threshold logic.
 */
class AlarmPolicy
{
public:
    /**
     * @brief Construct with thresholds.
     * @param spo2Th SpO2 threshold
     * @param tempTh Temperature threshold
     */
    explicit AlarmPolicy(int spo2Th, double tempTh);
    /**
     * @brief Check if SpO2 is low.
     * @param spo2 SpO2 value
     * @return true if below threshold
     */
    bool lowSpO2(int spo2) const;
    /**
     * @brief Check if temperature is high.
     * @param t Temperature value
     * @return true if above threshold
     */
    bool highTemp(double t) const;
private:
    int spo2Th_;
    double tempTh_;
};

/**
 * @brief Manages alarm reactions and escalation.
 */
class AlarmManager
{
public:
    /**
     * @brief Construct with policy, logger, and server path.
     */
    AlarmManager(const AlarmPolicy& policy, Logger& logger, const std::string& serverPath);
    /**
     * @brief Evaluate and handle alarm conditions.
     * @param patientId Patient ID
     * @param patientName Patient name
     * @param v Vital signs
     * @return true if critical escalation occurred
     */
    bool evaluateAndHandle(const std::string& patientId, const std::string& patientName, const VitalSigns& v);
private:
    void escalate(const std::string& message);
    const AlarmPolicy& policy_;
    Logger& logger_;
    std::string serverPath_;
};

/**
 * @brief Patient value object.
 */
class Patient
{
public:
    /**
     * @brief Construct a patient.
     * @param id Patient ID
     * @param name Patient name
     * @param age Patient age
     */
    Patient(std::string id, std::string name, int age);
    /** @brief Get patient ID. */
    const std::string& id() const;
    /** @brief Get patient name. */
    const std::string& name() const;
    /** @brief Get patient age. */
    int age() const;
private:
    std::string id_;
    std::string name_;
    int age_;
};

/**
 * @brief Coordinates reading, logging, and alarm checks.
 */
class Monitor
{
public:
    /**
     * @brief Construct a monitor.
     * @param sensor Sensor instance
     * @param patient Patient info
     * @param alarmMgr Alarm manager
     * @param logger Logger
     * @param cfg Configuration
     */
    Monitor(std::unique_ptr<ISensor> sensor,
            Patient patient,
            AlarmManager& alarmMgr,
            Logger& logger,
            MonitorConfig cfg);
    /**
     * @brief Run the monitor for a number of iterations.
     * @param iterations Number of samples to take
     */
    void run(int iterations = 20);
private:
    void logStatus(const VitalSigns& v);
    std::unique_ptr<ISensor> sensor_;
    Patient patient_;
    AlarmManager& alarmMgr_;
    Logger& logger_;
    MonitorConfig cfg_;
};

#endif // PULSE_OXIMETER_MONITOR_HPP
