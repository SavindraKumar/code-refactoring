#include "PatientRecord.hpp"

PatientRecord::PatientRecord(const std::string& patientName, int age, const std::string& diagnosis)
    : patientName(patientName), age(age), diagnosis(diagnosis),
      insuranceProvider(""), emergencyContact("") {} // dispensables initialized but never used

std::string PatientRecord::getPatientName() const {
    return patientName;
}

int PatientRecord::getAge() const {
    return age;
}

std::string PatientRecord::getDiagnosis() const {
    return diagnosis;
}

// Dispensable getters
std::string PatientRecord::getInsuranceProvider() const {
    return insuranceProvider;
}

std::string PatientRecord::getEmergencyContact() const {
    return emergencyContact;
}
