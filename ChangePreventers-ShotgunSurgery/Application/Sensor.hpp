#pragma once
#include <string>

class Sensor
{
public:
    std::string id;
    double voltage;

    Sensor(const std::string& id, double v);
};
