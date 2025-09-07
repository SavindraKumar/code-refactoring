#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(double value) : value_(value)
{

}

void TemperatureSensor::processReading() const
{
    std::cout << "[Temperature Sensor] Reading: " << value_ << " °C" << std::endl;
    if (value_ > 75)
    {
        std::cout << "⚠ Overheating detected!" << std::endl;
    }
}
