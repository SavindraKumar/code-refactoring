#pragma once
class Sensor;

class ISensorObserver
{
public:
    virtual ~ISensorObserver() = default;
    virtual void update(const Sensor& s) = 0;
};
