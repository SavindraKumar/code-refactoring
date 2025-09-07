#ifndef SENSOR_HPP
#define SENSOR_HPP

/**
 * @class Sensor
 * @brief Abstract base class representing a sensor.
 */
class ISensor
{
public:
    virtual ~ISensor() = default;

    /**
     * @brief Process the reading of the sensor.
     */
    virtual void processReading() const = 0;
};

#endif // SENSOR_HPP
