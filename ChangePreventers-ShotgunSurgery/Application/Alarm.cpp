#include "Alarm.hpp"

void Alarm::check(const Sensor& s)
{
    if (s.voltage > 250)
        std::cout << "ALARM: High voltage detected in " << s.id << "\n";
}
