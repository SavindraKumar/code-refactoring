#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
public:
    Patient(const std::string& name, int age, double bloodPressure, double sugarLevel);

    std::string getName() const;
    std::string getHealthStatus() const; // ✅ Encapsulated

private:
    std::string name;
    int age;
    double bloodPressure; // mmHg
    double sugarLevel;    // mg/dL
};

#endif
