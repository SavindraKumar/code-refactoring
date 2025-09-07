#include "SensorReading.hpp"
#include <iostream>

int main() {
    SensorReading sensor("S1", 230.0, 10.0);

    // External logic does all the work
    double power = sensor.getVoltage() * sensor.getCurrent();

    std::cout << "Sensor: " << sensor.getId()
              << " - Power: " << power << " W" << std::endl;

    return 0;
}
