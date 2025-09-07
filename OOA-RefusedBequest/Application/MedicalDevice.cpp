#include "MedicalDevice.hpp"

MedicalDevice::MedicalDevice(const std::string& id) : deviceId(id)
{

}

void MedicalDevice::start() const
{
    std::cout << "Starting device: " << deviceId << "\n";
}

void MedicalDevice::stop() const
{
    std::cout << "Stopping device: " << deviceId << "\n";
}

void MedicalDevice::calibrate() const
{
    std::cout << "Calibrating device: " << deviceId << "\n";
}
