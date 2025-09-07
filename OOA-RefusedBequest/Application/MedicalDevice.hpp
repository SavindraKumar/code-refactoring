#pragma once
#include <iostream>
#include <string>

class MedicalDevice
{
protected:
    std::string deviceId;

public:
    MedicalDevice(const std::string& id);
    virtual ~MedicalDevice() = default;

    virtual void start() const;
    virtual void stop() const;
    virtual void calibrate() const; // Not all devices need this
};
