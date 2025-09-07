#include "VoltageSensor.hpp"

VoltageSensor::VoltageSensor(double value) : value_(value)
{

}

void VoltageSensor::processReading() const
{
    std::cout << "[Voltage Sensor] Reading: " << value_ << " V" << std::endl;

    if (value_ > 240)
    {
        std::cout << "⚠ Overvoltage detected!" << std::endl;
    }
}
