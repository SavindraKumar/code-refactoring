#ifndef TYPES_HPP
#define TYPES_HPP
#include <string>
#include <chrono>
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
#endif // TYPES_HPP
