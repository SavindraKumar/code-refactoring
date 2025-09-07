#include "PatientManagementSystem.hpp"
#include <fstream>

// Constructor
PatientManagementSystem::PatientManagementSystem(const std::string& name, int age, bool insurance)
    : patientName(name), patientAge(age), hasInsurance(insurance), outstandingBill(0.0) {}

// Patient info
void PatientManagementSystem::updatePatientInfo(const std::string& newName, int newAge) {
    patientName = newName;
    patientAge = newAge;
}

// Appointments
void PatientManagementSystem::scheduleAppointment(const std::string& date, const std::string& doctor) {
    appointments.push_back({date, doctor});
}

void PatientManagementSystem::printAppointments() const {
    std::cout << "Appointments for " << patientName << ":\n";
    for (const auto& appt : appointments) {
        std::cout << " - " << appt.date << " with Dr. " << appt.doctor << "\n";
    }
}

// Medical history
void PatientManagementSystem::addMedicalRecord(const std::string& diagnosis, const std::string& treatment) {
    history.push_back({diagnosis, treatment});
}

void PatientManagementSystem::printMedicalHistory() const {
    std::cout << "Medical history for " << patientName << ":\n";
    for (const auto& rec : history) {
        std::cout << " - " << rec.diagnosis << " treated with " << rec.treatment << "\n";
    }
}

// Billing
void PatientManagementSystem::addCharge(double amount) {
    outstandingBill += amount;
}

void PatientManagementSystem::payBill(double amount) {
    outstandingBill -= amount;
}

double PatientManagementSystem::getOutstandingBill() const {
    return outstandingBill;
}

// Insurance
void PatientManagementSystem::verifyInsurance() const {
    if (hasInsurance) {
        std::cout << "Insurance verified for " << patientName << "\n";
    } else {
        std::cout << patientName << " has no insurance.\n";
    }
}

// Report generation
void PatientManagementSystem::generatePatientReport() const {
    std::ofstream file(patientName + "_report.txt");
    file << "Patient: " << patientName << "\n";
    file << "Age: " << patientAge << "\n";
    file << "Outstanding Bill: $" << outstandingBill << "\n";
    file << "Appointments: " << appointments.size() << "\n";
    file << "Medical Records: " << history.size() << "\n";
    file.close();
}
