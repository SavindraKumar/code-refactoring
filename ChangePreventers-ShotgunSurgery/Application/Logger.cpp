#include "Logger.hpp"

void Logger::log(const Sensor& s)
{
    std::cout << "Logging sensor " << s.id << " Voltage=" << s.voltage << "V\n";
}
