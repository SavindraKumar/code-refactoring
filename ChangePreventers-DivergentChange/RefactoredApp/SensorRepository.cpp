#include "SensorRepository.hpp"
#include <iostream>

void SensorRepository::save(const Sensor& sensor)
{
    std::cout << "Saving sensor " << sensor.getId()
              << " V=" << sensor.getVoltage()
              << " I=" << sensor.getCurrent() << " to DB\n";
}
