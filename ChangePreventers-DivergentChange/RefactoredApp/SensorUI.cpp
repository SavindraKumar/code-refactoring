#include "SensorUI.hpp"
#include <iostream>

void SensorUI::display(const Sensor& sensor)
{
    std::cout << "Displaying " << sensor.getId()
              << ": V=" << sensor.getVoltage()
              << "V, I=" << sensor.getCurrent() << "A\n";
}
