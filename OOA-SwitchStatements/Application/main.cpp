#include "Sensor.hpp"

int main()
{
    Sensor v(SensorType::Voltage, 250);
    Sensor c(SensorType::Current, 12);
    Sensor t(SensorType::Temperature, 80);
    Sensor p(SensorType::Pressure, 220);

    v.processReading();
    c.processReading();
    t.processReading();
    p.processReading();

    return 0;
}
