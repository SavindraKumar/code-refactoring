#pragma once
#include "../RefactoredApp-Composition/Calibrator.hpp"
#include "../RefactoredApp-Composition/Device.hpp"

class ECGMachine : public Device
{
private:
    Calibrator calibrator;

public:
    ECGMachine(const std::string& id);
    void calibrate() const;
};
