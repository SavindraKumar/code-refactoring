#pragma once
#include "MedicalDevice.hpp"

class Thermometer : public MedicalDevice
{
public:
    Thermometer(const std::string& id);

    // Thermometer doesn’t actually need calibration,
    // but is forced to override this method.
    void calibrate() const override;
};
