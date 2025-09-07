#include "Prescription.hpp"
#include <iostream>

Prescription::Prescription(const std::string& patientName,
                           const std::string& doctorName,
                           const std::string& medicationName,
                           const Dosage& dosage,
                           const Frequency& frequency,
                           const Duration& duration)
    : patientName(patientName),
      doctorName(doctorName),
      medicationName(medicationName),
      dosage(dosage),
      frequency(frequency),
      duration(duration) {}

void Prescription::print() const {
    std::cout << "Prescription for " << patientName
              << " by Dr. " << doctorName << "\n"
              << "Medication: " << medicationName << "\n"
              << "Dosage: " << dosage.toString() << "\n"
              << "Frequency: " << frequency.toString() << "\n"
              << "Duration: " << duration.toString() << "\n";
}
