#pragma once
#include "ISensorObserver.hpp"
#include <iostream>

class Logger : public ISensorObserver
{
public:
    void update(const Sensor& s) override;
};
