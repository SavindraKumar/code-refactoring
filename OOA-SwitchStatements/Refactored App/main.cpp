#include "VoltageSensor.hpp"
#include "CurrentSensor.hpp"
#include "TemperatureSensor.hpp"
#include "PressureSensor.hpp"

#include <vector>
#include <memory>
#include <iterator>

int main() {
    std::vector<std::unique_ptr<Sensor>> sensors;

    sensors.push_back(std::make_unique<VoltageSensor>(250));
    sensors.push_back(std::make_unique<CurrentSensor>(12));
    sensors.push_back(std::make_unique<TemperatureSensor>(80));
    sensors.push_back(std::make_unique<PressureSensor>(220));


    for (const auto& sensor : sensors) {
        sensor->processReading();
    }

    return 0;
}
