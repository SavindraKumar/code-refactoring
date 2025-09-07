#include "SensorReading.hpp"

SensorReading::SensorReading(const std::string& id, double voltage, double current)
    : id(id), voltage(voltage), current(current)
{

}

double SensorReading::calculatePower() const
{
    return voltage * current;
}

void SensorReading::printSummary() const
{
    std::cout << "Sensor: " << id
              << " - Voltage: " << voltage << " V"
              << ", Current: " << current << " A"
              << ", Power: " << calculatePower() << " W" << std::endl;
}
