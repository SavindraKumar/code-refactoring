#include "Thermometer.hpp"

Thermometer::Thermometer(const std::string& id) : MedicalDevice(id)
{

}

void Thermometer::calibrate() const
{
    // Refused bequest → doesn’t make sense for a thermometer
    std::cout << "Thermometer " << deviceId
              << " does not require calibration.\n";
}
