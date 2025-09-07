#ifndef MONITOR_HPP
#define MONITOR_HPP
#include "ISensor.hpp"
#include "Patient.hpp"
#include "AlarmManager.hpp"
#include "Logger.hpp"
#include "Types.hpp"
#include <memory>
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
#endif // MONITOR_HPP
