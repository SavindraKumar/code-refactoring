#include "PatientRecord.hpp"

PatientRecord::PatientRecord(const std::string& patientName, int age, const std::string& diagnosis)
    : patientName(patientName), age(age), diagnosis(diagnosis) {}

std::string PatientRecord::getPatientName() const {
    return patientName;
}

int PatientRecord::getAge() const {
    return age;
}

std::string PatientRecord::getDiagnosis() const {
    return diagnosis;
}