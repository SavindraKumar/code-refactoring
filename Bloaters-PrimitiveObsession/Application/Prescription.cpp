#include "Prescription.hpp"
#include <iostream>

Prescription::Prescription(const std::string& patientName,
                           const std::string& doctorName,
                           const std::string& medicationName,
                           const std::string& dosage,
                           const std::string& frequency,
                           const std::string& duration)
    : patientName(patientName),
      doctorName(doctorName),
      medicationName(medicationName),
      dosage(dosage),
      frequency(frequency),
      duration(duration) {}

void Prescription::print() const {
    std::cout << "Prescription for " << patientName << " by Dr. " << doctorName << "\n"
              << "Medication: " << medicationName << "\n"
              << "Dosage: " << dosage << "\n"
              << "Frequency: " << frequency << "\n"
              << "Duration: " << duration << "\n";
}
