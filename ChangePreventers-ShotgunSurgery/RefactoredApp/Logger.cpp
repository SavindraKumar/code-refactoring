#include "Logger.hpp"
#include "Sensor.hpp"

void Logger::update(const Sensor& s)
{
    std::cout << "Logging: " << s.getId() << " Voltage=" << s.getVoltage() << "V\n";
}
