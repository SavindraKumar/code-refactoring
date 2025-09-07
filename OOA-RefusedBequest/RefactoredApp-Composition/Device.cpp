#include "../RefactoredApp-Composition/Device.hpp"

Device::Device(const std::string& id) : deviceId(id)
{
}

void Device::start() const
{
    std::cout << "Starting device: " << deviceId << "\n";
}

void Device::stop() const
{
    std::cout << "Stopping device: " << deviceId << "\n";
}
