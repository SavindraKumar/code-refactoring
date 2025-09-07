#include "Sensor.hpp"

Sensor::Sensor(const std::string& id, double v, double c)
    : sensorId(id), voltage(v), current(c)
{

}

std::string Sensor::getId() const
{
	return sensorId;
}

double Sensor::getVoltage() const
{
	return voltage;
}

double Sensor::getCurrent() const
{
	return current;
}
