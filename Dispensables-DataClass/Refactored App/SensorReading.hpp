#ifndef SENSORREADING_HPP
#define SENSORREADING_HPP

#include <string>
#include <iostream>

/**
 * @class SensorReading
 * @brief Represents an electrical sensor with behavior.
 *
 * Refactored to include methods for calculating power.
 */
class SensorReading
{
public:
    SensorReading(const std::string& id, double voltage, double current);

    /**
     * @brief Calculates the power (W = V * I).
     * @return Power in watts.
     */
    double calculatePower() const;

    /**
     * @brief Prints a summary of the sensor reading.
     */
    void printSummary() const;

private:
    std::string id;    ///< Sensor identifier
    double voltage;    ///< Voltage in volts
    double current;    ///< Current in amperes
};

#endif // SENSORREADING_HPP
