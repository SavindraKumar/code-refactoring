#include "Sensor.hpp"
#include "SensorRepository.hpp"
#include "SensorUI.hpp"
#include "PowerCalculator.hpp"
#include <iostream>

int main()
{
    Sensor s("SENSOR-2", 120.0, 10.0);

    SensorRepository repo;
    repo.save(s);

    SensorUI ui;
    ui.display(s);

    PowerCalculator calc;
    std::cout << "Power = " << calc.calculate(s) << "W\n";

    return 0;
}
