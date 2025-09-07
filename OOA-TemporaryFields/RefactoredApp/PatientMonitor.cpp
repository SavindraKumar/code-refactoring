#include "PatientMonitor.hpp"

// Base class
PatientMonitor::PatientMonitor(double id) : patientId(id)
{

}

void PatientMonitor::analyze() const
{
    std::cout << "Monitoring Patient: " << patientId << "\n";
}

// HeartRateMonitor
HeartRateMonitor::HeartRateMonitor(double id, int hr, int spo2)
    : PatientMonitor(id), heartRate(hr), oxygenSaturation(spo2)
{

}

void HeartRateMonitor::analyze() const
{
    PatientMonitor::analyze();
    std::cout << "Heart Rate: " << heartRate
              << " bpm, SpO2: " << oxygenSaturation << "%\n";
}

// BloodPressureMonitor
BloodPressureMonitor::BloodPressureMonitor(double id, int sys, int dia)
    : PatientMonitor(id), systolic(sys), diastolic(dia)
{

}

void BloodPressureMonitor::analyze() const
{
    PatientMonitor::analyze();
    std::cout << "Blood Pressure: " << systolic
              << "/" << diastolic << " mmHg\n";
}
