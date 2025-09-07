#ifndef SENSORREADING_HPP
#define SENSORREADING_HPP

#include <string>

/**
 * @class SensorReading
 * @brief A data class that only stores electrical sensor values.
 *
 * Dispensable because it only provides getters and setters
 * without any behavior.
 */
class SensorReading
{
public:
    SensorReading(const std::string& id, double voltage, double current);

    std::string getId() const;
    void setId(const std::string& id);

    double getVoltage() const;
    void setVoltage(double voltage);

    double getCurrent() const;
    void setCurrent(double current);

private:
    std::string id;    ///< Sensor identifier
    double voltage;    ///< Voltage value in volts
    double current;    ///< Current value in amperes
};

#endif // SENSORREADING_HPP
