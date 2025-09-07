#ifndef PATIENTRECORD_HPP
#define PATIENTRECORD_HPP

#include <string>

class PatientRecord {
private:
    std::string patientName;
    int age;
    std::string diagnosis;

    // Dispensables
    std::string insuranceProvider; // never used
    std::string emergencyContact;  // never used

public:
    PatientRecord(const std::string& patientName, int age, const std::string& diagnosis);

    std::string getPatientName() const;
    int getAge() const;
    std::string getDiagnosis() const;

    // Dispensable getters
    std::string getInsuranceProvider() const; // dispensable
    std::string getEmergencyContact() const;  // dispensable
};

#endif // PATIENTRECORD_HPP
