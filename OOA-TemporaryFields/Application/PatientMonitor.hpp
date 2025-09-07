#pragma once
#include <iostream>
#include <optional>

class PatientMonitor
{
private:
    double patientId;

    // Temporary fields: only used in heart rate monitoring
    std::optional<int> heartRate;
    std::optional<int> oxygenSaturation;

    // Temporary fields: only used in blood pressure monitoring
    std::optional<int> systolic;
    std::optional<int> diastolic;

public:
    PatientMonitor(double id);

    void setHeartRateMonitoring(int hr, int spo2);
    void setBloodPressureMonitoring(int sys, int dia);

    void analyze() const;
};
