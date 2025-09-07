#ifndef CURRENTSENSOR_HPP
#define CURRENTSENSOR_HPP

#include "ISensor.hpp"
#include <iostream>

/**
 * @class CurrentSensor
 * @brief A sensor for measuring current.
 */
class CurrentSensor : public ISensor
{
public:
    CurrentSensor(double value);
    void processReading() const override;

private:
    double value_;
};

#endif // CURRENTSENSOR_HPP
