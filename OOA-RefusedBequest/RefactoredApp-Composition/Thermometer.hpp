#pragma once
#include "../RefactoredApp-Composition/Device.hpp"

class Thermometer : public Device
{
public:
    Thermometer(const std::string& id);
};
