#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
public:
    Patient(const std::string& name, const std::string& history);

    std::string getName() const;
    std::string getMedicalHistorySummary() const; // ✅ controlled access

private:
    std::string name;
    std::string medicalHistory; // sensitive info
};

#endif
