#include "ECGMachine.hpp"

ECGMachine::ECGMachine(const std::string& id) : CalibratableDevice(id)
{

}

void ECGMachine::calibrate() const
{
    std::cout << "Calibrating ECG Machine: " << deviceId << "\n";
}
