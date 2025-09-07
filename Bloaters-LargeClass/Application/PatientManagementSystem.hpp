#ifndef PATIENT_MANAGEMENT_SYSTEM_HPP
#define PATIENT_MANAGEMENT_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Appointment {
    std::string date;
    std::string doctor;
};

struct MedicalRecord {
    std::string diagnosis;
    std::string treatment;
};

class PatientManagementSystem {
private:
    std::string patientName;
    int patientAge;
    std::vector<Appointment> appointments;
    std::vector<MedicalRecord> history;
    bool hasInsurance;
    double outstandingBill;

public:
    PatientManagementSystem(const std::string& name, int age, bool insurance);

    // Patient info
    void updatePatientInfo(const std::string& newName, int newAge);

    // Appointments
    void scheduleAppointment(const std::string& date, const std::string& doctor);
    void printAppointments() const;

    // Medical history
    void addMedicalRecord(const std::string& diagnosis, const std::string& treatment);
    void printMedicalHistory() const;

    // Billing
    void addCharge(double amount);
    void payBill(double amount);
    double getOutstandingBill() const;

    // Insurance
    void verifyInsurance() const;

    // Report generation
    void generatePatientReport() const;
};

#endif // PATIENT_MANAGEMENT_SYSTEM_HPP
