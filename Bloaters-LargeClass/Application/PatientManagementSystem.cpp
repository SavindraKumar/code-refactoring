#include "PatientManagementSystem.hpp"
#include <fstream>

// Constructor
PatientManagementSystem::PatientManagementSystem(const std::string& name, int age, bool insurance)
    : patient(name, age, insurance) {}

// Patient info
void PatientManagementSystem::updatePatientInfo(const std::string& newName, int newAge)
{
    patient.updateInfo(newName, newAge);
}

// Appointments
void PatientManagementSystem::scheduleAppointment(const std::string& date, const std::string& doctor)
{
    appointmentManager.schedule(date, doctor);
}

void PatientManagementSystem::printAppointments() const
{
    appointmentManager.print(patient.getName());
}

// Medical history
void PatientManagementSystem::addMedicalRecord(const std::string& diagnosis, const std::string& treatment)
{
    medicalHistory.add(diagnosis, treatment);
}

void PatientManagementSystem::printMedicalHistory() const
{
    medicalHistory.print(patient.getName());
}

// Billing
void PatientManagementSystem::addCharge(double amount)
{
    billing.addCharge(amount);
}

void PatientManagementSystem::payBill(double amount)
{
    billing.pay(amount);
}

double PatientManagementSystem::getOutstandingBill() const
{
    return billing.getOutstanding();
}

// Insurance
void PatientManagementSystem::verifyInsurance() const
{
    patient.verifyInsurance();
}

// Report generation
void PatientManagementSystem::generatePatientReport() const
{
    std::ofstream file(patient.getName() + "_report.txt");
    file << "Patient: " << patient.getName() << "\n";
    file << "Age: " << patient.getAge() << "\n";
    file << "Outstanding Bill: $" << billing.getOutstanding() << "\n";
    file << "Appointments: " << appointmentManager.count() << "\n";
    file << "Medical Records: " << medicalHistory.count() << "\n";
    file.close();
}