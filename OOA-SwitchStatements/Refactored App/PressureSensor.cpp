#include "PressureSensor.hpp"

PressureSensor::PressureSensor(double value) : value_(value)
{

}

void PressureSensor::processReading() const
{
    std::cout << "[Pressure Sensor] Reading: " << value_ << " Pa" << std::endl;

    if (value_ > 200)
    {
        std::cout << "⚠ Overpressure detected!" << std::endl;
    }
}
