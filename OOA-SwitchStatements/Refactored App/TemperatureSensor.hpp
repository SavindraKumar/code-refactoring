#ifndef TEMPERATURESENSOR_HPP
#define TEMPERATURESENSOR_HPP

#include "ISensor.hpp"
#include <iostream>

/**
 * @class TemperatureSensor
 * @brief A sensor for measuring temperature.
 */
class TemperatureSensor : public ISensor
{
public:
    TemperatureSensor(double value);
    void processReading() const override;

private:
    double value_;
};

#endif // TEMPERATURESENSOR_HPP
