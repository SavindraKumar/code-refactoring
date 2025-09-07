#include "PatientRecord.hpp"
#include <iostream>

int main() {
    // Create a patient record
    PatientRecord patient("Alice Brown", 32, "Hypertension");

    std::cout << "Patient: " << patient.getPatientName() << std::endl;
    std::cout << "Age: " << patient.getAge() << std::endl;
    std::cout << "Diagnosis: " << patient.getDiagnosis() << std::endl;

    // The dispensable fields and getters are never used
    // std::cout << patient.getInsuranceProvider() << std::endl; // not needed
    // std::cout << patient.getEmergencyContact() << std::endl;  // not needed

    return 0;
}
