#ifndef PRESSURESENSOR_HPP
#define PRESSURESENSOR_HPP

#include "ISensor.hpp"
#include <iostream>

/**
 * @class PressureSensor
 * @brief A sensor for measuring pressure.
 */
class PressureSensor : public ISensor
{
public:
    PressureSensor(double value);
    void processReading() const override;

private:
    double value_;
};

#endif // PRESSURESENSOR_HPP
