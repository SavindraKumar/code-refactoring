#pragma once
#include <string>

class Sensor
{
private:
    std::string sensorId;
    double voltage;
    double current;

public:
    Sensor(const std::string& id, double v, double c);

    std::string getId() const;
    double getVoltage() const;
    double getCurrent() const;
};
