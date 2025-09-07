#pragma once
#include <iostream>

class PatientMonitor
{
protected:
    double patientId;

public:
    PatientMonitor(double id);
    virtual ~PatientMonitor() = default;

    virtual void analyze() const;
};

class HeartRateMonitor : public PatientMonitor
{
private:
    int heartRate;
    int oxygenSaturation;

public:
    HeartRateMonitor(double id, int hr, int spo2);
    void analyze() const override;
};

class BloodPressureMonitor : public PatientMonitor
{
private:
    int systolic;
    int diastolic;

public:
    BloodPressureMonitor(double id, int sys, int dia);
    void analyze() const override;
};
