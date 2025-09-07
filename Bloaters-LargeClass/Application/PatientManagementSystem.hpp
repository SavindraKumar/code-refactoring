#ifndef PATIENT_MANAGEMENT_SYSTEM_HPP
#define PATIENT_MANAGEMENT_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Patient.hpp"
#include "AppointmentManager.hpp"
#include "MedicalHistory.hpp"
#include "Billing.hpp"

class PatientManagementSystem
{
private:
    Patient patient;
    AppointmentManager appointmentManager;
    MedicalHistory medicalHistory;
    Billing billing;

public:
    PatientManagementSystem(const std::string& name, int age, bool insurance);
    void updatePatientInfo(const std::string& newName, int newAge);
    void scheduleAppointment(const std::string& date, const std::string& doctor);
    void printAppointments() const;
    void addMedicalRecord(const std::string& diagnosis, const std::string& treatment);
    void printMedicalHistory() const;
    void addCharge(double amount);
    void payBill(double amount);
    double getOutstandingBill() const;
    void verifyInsurance() const;
    void generatePatientReport() const;
};

#endif // PATIENT_MANAGEMENT_SYSTEM_HPP