#include "PatientMonitor.hpp"

int main()
{
    PatientMonitor monitor1(101);
    monitor1.setHeartRateMonitoring(72, 98);
    monitor1.analyze();

    PatientMonitor monitor2(102);
    monitor2.setBloodPressureMonitoring(120, 80);
    monitor2.analyze();

    return 0;
}
