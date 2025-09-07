#pragma once
#include <iostream>
#include <string>

class Device
{
protected:
    std::string deviceId;

public:
    Device(const std::string& id);
    virtual ~Device() = default;

    virtual void start() const;
    virtual void stop() const;
};
