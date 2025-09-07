#pragma once
#include <string>
#include <vector>
#include <memory>

class ISensorObserver;

class Sensor
{
private:
    std::string id;
    double voltage;
    std::vector<ISensorObserver*> observers;

public:
    Sensor(const std::string& id_, double v);

    void attach(ISensorObserver* obs);
    void setVoltage(double v);
    std::string getId() const;
    double getVoltage() const;
    void notify();
};
