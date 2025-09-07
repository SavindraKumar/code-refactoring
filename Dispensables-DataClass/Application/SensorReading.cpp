#include "SensorReading.hpp"

SensorReading::SensorReading(const std::string& id, double voltage, double current)
    : id(id), voltage(voltage), current(current)
{

}

std::string SensorReading::getId() const
{
	return id;
}

void SensorReading::setId(const std::string& id)
{
	this->id = id;
}

double SensorReading::getVoltage() const
{
	return voltage;
}


void SensorReading::setVoltage(double voltage)
{
	this->voltage = voltage;
}

double SensorReading::getCurrent() const
{
	return current;
}

void SensorReading::setCurrent(double current)
{
	this->current = current;
}
