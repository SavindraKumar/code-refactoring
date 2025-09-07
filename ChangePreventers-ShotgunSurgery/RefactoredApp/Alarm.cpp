#include "Alarm.hpp"
#include "Sensor.hpp"

void Alarm::update(const Sensor& s)
{
    if (s.getVoltage() > 250)
        std::cout << "ALARM: High voltage in " << s.getId() << "\n";
}
