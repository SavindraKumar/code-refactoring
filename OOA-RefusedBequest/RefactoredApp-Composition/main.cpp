#include <memory>
#include <vector>
#include "../RefactoredApp-Composition/ECGMachine.hpp"
#include "../RefactoredApp-Composition/Thermometer.hpp"

int main()
{
    std::vector<std::unique_ptr<Device>> devices;
    devices.push_back(std::make_unique<Thermometer>("THERMO-101"));
    devices.push_back(std::make_unique<ECGMachine>("ECG-202"));

    for (const auto& dev : devices)
    {
        dev->start();

        // ECGMachine supports calibration, Thermometer does not
        if (auto ecg = dynamic_cast<ECGMachine*>(dev.get()))
        {
            ecg->calibrate();
        }

        dev->stop();
        std::cout << "----------------------\n";
    }

    return 0;
}
