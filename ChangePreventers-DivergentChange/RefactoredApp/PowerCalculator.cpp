#include "PowerCalculator.hpp"

double PowerCalculator::calculate(const Sensor& sensor)
{
    return sensor.getVoltage() * sensor.getCurrent();
}
