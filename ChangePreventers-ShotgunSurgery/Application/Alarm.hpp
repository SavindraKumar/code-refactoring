#pragma once
#include "Sensor.hpp"
#include <iostream>

class Alarm
{
public:
    void check(const Sensor& s);
};
