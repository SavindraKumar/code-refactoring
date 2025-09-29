#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Doctor; // forward declaration

class Patient
{
    friend class Doctor; // ❌ Inappropriate Intimacy

public:
    Patient(const std::string& name, const std::string& history);

private:
    std::string name;
    std::string medicalHistory; // sensitive info
};

#endif
