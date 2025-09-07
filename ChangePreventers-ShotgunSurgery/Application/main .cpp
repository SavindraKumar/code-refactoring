#include "Sensor.hpp"
#include "Logger.hpp"
#include "Alarm.hpp"

int main()
{
    Sensor s("S-111", 260);

    Logger logger;
    Alarm alarm;

    logger.log(s);
    alarm.check(s);

    return 0;
}
