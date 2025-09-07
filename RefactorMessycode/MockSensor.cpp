#include "MockSensor.hpp"

MockSensor::MockSensor()
  : rng_(std::random_device{}()),
    spo2Dist_(85, 104),
    tempDeciDist_(350, 740)
{
}

VitalSigns MockSensor::read()
{
    VitalSigns v;
    v.spo2 = spo2Dist_(rng_);
    v.tempC = tempDeciDist_(rng_) / 10.0;
    return v;
}
