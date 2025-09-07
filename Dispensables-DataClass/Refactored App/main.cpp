#include "SensorReading.hpp"

int main()
{
    SensorReading sensor("S1", 230.0, 10.0);
    sensor.printSummary(); // Sensor "owns" the behavior now

    return 0;
}
