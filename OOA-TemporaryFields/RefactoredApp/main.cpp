#include "PatientMonitor.hpp"
#include <memory>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<PatientMonitor>> monitors;

    monitors.push_back(std::make_unique<HeartRateMonitor>(101, 72, 98));
    monitors.push_back(std::make_unique<BloodPressureMonitor>(102, 120, 80));

    for (const auto& monitor : monitors)
    {
        monitor->analyze();
    }

    return 0;
}
