#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>

/**
 * @enum SensorType
 * @brief Enumerates different types of sensors in the system.
 */
enum class SensorType { Voltage, Current, Temperature, Pressure };

/**
 * @class Sensor
 * @brief Represents a sensor with a type and a reading value.
 *
 * This class contains a large switch statement in processReading(),
 * making it an example of the "Switch Statement" code smell.
 */
class Sensor
{
public:
    /**
     * @brief Constructs a Sensor with a given type and value.
     * @param type Type of the sensor.
     * @param value Sensor reading value.
     */
    Sensor(SensorType type, double value);

    /**
     * @brief Processes the sensor reading based on its type.
     */
    void processReading() const;

private:
    SensorType type_;   ///< Type of the sensor.
    double value_;      ///< Sensor reading value.
};

#endif // SENSOR_HPP
