#pragma once
#include "CalibratableDevice.hpp"

class ECGMachine : public CalibratableDevice
{
public:
    ECGMachine(const std::string& id);
    void calibrate() const override;
};
