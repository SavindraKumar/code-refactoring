#ifndef ISENSOR_HPP
#define ISENSOR_HPP
#include "Types.hpp"
/**
 * @brief Sensor interface for reading vital signs.
 */
class ISensor {
public:
    /**
     * @brief Read current vital signs.
     * @return VitalSigns struct
     */
    virtual VitalSigns read() = 0;
    virtual ~ISensor() = default;
};
#endif // ISENSOR_HPP
