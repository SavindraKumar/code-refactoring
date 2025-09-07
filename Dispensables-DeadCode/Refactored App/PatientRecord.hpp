#ifndef PATIENTRECORD_HPP
#define PATIENTRECORD_HPP

#include <string>

class PatientRecord
{
private:
    std::string patientName;
    int age;
    std::string diagnosis;

public:
    PatientRecord(const std::string& patientName, int age, const std::string& diagnosis);

    std::string getPatientName() const;
    int getAge() const;
    std::string getDiagnosis() const;
};

#endif // PATIENTRECORD_HPP