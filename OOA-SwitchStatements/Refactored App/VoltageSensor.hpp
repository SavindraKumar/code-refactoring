#ifndef VOLTAGESENSOR_HPP
#define VOLTAGESENSOR_HPP

#include "ISensor.hpp"
#include <iostream>

/**
 * @class VoltageSensor
 * @brief A sensor for measuring voltage.
 */
class VoltageSensor : public ISensor
{
public:
    VoltageSensor(double value);
    void processReading() const override;

private:
    double value_;
};

#endif // VOLTAGESENSOR_HPP
