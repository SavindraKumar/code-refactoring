#include "Sensor.hpp"
#include "Logger.hpp"
#include "Alarm.hpp"

int main()
{
    Sensor s("S-222", 220);

    Logger logger;
    Alarm alarm;

    s.attach(&logger);
    s.attach(&alarm);

    s.setVoltage(260); // triggers observers

    return 0;
}
