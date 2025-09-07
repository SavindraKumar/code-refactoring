#include "CurrentSensor.hpp"

CurrentSensor::CurrentSensor(double value) : value_(value)
{

}

void CurrentSensor::processReading() const
{
    std::cout << "[Current Sensor] Reading: " << value_ << " A" << std::endl;

    if (value_ > 10)
    {
        std::cout << "⚠ Overcurrent detected!" << std::endl;
    }
}
