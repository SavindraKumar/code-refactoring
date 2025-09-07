#pragma once
#include "Device.hpp"

class CalibratableDevice : public Device
{
public:
    CalibratableDevice(const std::string& id);
    virtual void calibrate() const = 0; // Pure virtual
};
