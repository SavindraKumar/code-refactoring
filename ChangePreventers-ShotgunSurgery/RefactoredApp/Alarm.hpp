#pragma once
#include "ISensorObserver.hpp"
#include <iostream>

class Alarm : public ISensorObserver
{
public:
    void update(const Sensor& s) override;
};
