#include "Thermometer.hpp"
#include "ECGMachine.hpp"
#include <memory>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<Device>> devices;
    devices.push_back(std::make_unique<Thermometer>("THERMO-101"));
    devices.push_back(std::make_unique<ECGMachine>("ECG-202"));

    for (const auto& dev : devices)
    {
        dev->start();

        // Dynamic cast to check if device supports calibration
        if (auto calib = dynamic_cast<CalibratableDevice*>(dev.get()))
        {
            calib->calibrate();
        }

        dev->stop();
        std::cout << "----------------------\n";
    }

    return 0;
}
