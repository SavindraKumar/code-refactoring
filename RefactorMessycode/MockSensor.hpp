#ifndef MOCKSENSOR_HPP
#define MOCKSENSOR_HPP
#include "ISensor.hpp"
#include <random>
/**
 * @brief Mock sensor simulating hardware readings.
 */
class MockSensor : public ISensor
{
public:
    MockSensor();
    VitalSigns read() override;
private:
    std::mt19937 rng_;
    std::uniform_int_distribution<int> spo2Dist_;
    std::uniform_int_distribution<int> tempDeciDist_;
};
#endif // MOCKSENSOR_HPP
