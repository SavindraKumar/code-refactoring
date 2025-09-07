#include "../RefactoredApp-Composition/ECGMachine.hpp"

ECGMachine::ECGMachine(const std::string& id) : Device(id)
{

}

void ECGMachine::calibrate() const
{
    calibrator.calibrate(deviceId);
}
