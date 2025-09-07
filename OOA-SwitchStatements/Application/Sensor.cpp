#include "Sensor.hpp"

Sensor::Sensor(SensorType type, double value)
    : type_(type), value_(value)
{

}

void Sensor::processReading() const
{
    switch (type_)
    {
        case SensorType::Voltage:
            std::cout << "[Voltage Sensor] Reading: " << value_ << " V" << std::endl;

            if (value_ > 240)
            {
                std::cout << "⚠ Overvoltage detected!" << std::endl;
            }
            break;

        case SensorType::Current:
            std::cout << "[Current Sensor] Reading: " << value_ << " A" << std::endl;

            if (value_ > 10)
            {
                std::cout << "⚠ Overcurrent detected!" << std::endl;
            }
            break;

        case SensorType::Temperature:
            std::cout << "[Temperature Sensor] Reading: " << value_ << " °C" << std::endl;

            if (value_ > 75)
            {
                std::cout << "⚠ Overheating detected!" << std::endl;
            }
            break;

        case SensorType::Pressure:
            std::cout << "[Pressure Sensor] Reading: " << value_ << " Pa" << std::endl;

            if (value_ > 200)
            {
                std::cout << "⚠ Overpressure detected!" << std::endl;
            }
            break;
    }
}
