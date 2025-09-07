#include "PatientMonitor.hpp"

PatientMonitor::PatientMonitor(double id) : patientId(id)
{

}

void PatientMonitor::setHeartRateMonitoring(int hr, int spo2)
{
    heartRate = hr;
    oxygenSaturation = spo2;
}

void PatientMonitor::setBloodPressureMonitoring(int sys, int dia)
{
    systolic = sys;
    diastolic = dia;
}

void PatientMonitor::analyze() const
{
    std::cout << "Monitoring Patient: " << patientId << "\n";

    if (heartRate.has_value() && oxygenSaturation.has_value())
    {
        std::cout << "Heart Rate: " << *heartRate
                  << " bpm, SpO2: " << *oxygenSaturation << "%\n";
    }

    if (systolic.has_value() && diastolic.has_value())
    {
        std::cout << "Blood Pressure: "
                  << *systolic << "/" << *diastolic << " mmHg\n";
    }
}
