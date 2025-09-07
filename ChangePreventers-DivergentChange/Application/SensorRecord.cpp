#include "SensorRecord.hpp"

SensorRecord::SensorRecord(const std::string& id, double v, double c)
    : sensorId(id), voltage(v), current(c)
{

}

void SensorRecord::saveToDatabase()
{
    std::cout << "Saving " << sensorId << " with V=" << voltage << " and I=" << current << " to DB\n";
}

void SensorRecord::displayUI()
{
    std::cout << "Displaying " << sensorId << ": Voltage=" << voltage << "V, Current=" << current << "A\n";
}

void SensorRecord::calculatePower()
{
    std::cout << "Power for " << sensorId << " = " << voltage * current << "W\n";
}
