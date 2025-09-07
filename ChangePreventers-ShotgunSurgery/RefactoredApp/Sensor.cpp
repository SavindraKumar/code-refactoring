#include "Sensor.hpp"
#include "ISensorObserver.hpp"

Sensor::Sensor(const std::string& id_, double v) : id(id_), voltage(v)
{

}

void Sensor::attach(ISensorObserver* obs)
{
	observers.push_back(obs);
}

void Sensor::setVoltage(double v)
{
    voltage = v;
    notify();
}

std::string Sensor::getId() const
{
	return id;
}

double Sensor::getVoltage() const
{
	return voltage;
}

void Sensor::notify()
{
    for (auto* obs : observers)
        obs->update(*this);
}
