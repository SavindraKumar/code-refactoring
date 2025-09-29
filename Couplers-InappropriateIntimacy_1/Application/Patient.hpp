#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
public:
    Patient(const std::string& name, int age, double bloodPressure, double sugarLevel);

    std::string getName() const;
    int getAge() const;
    double getBloodPressure() const;
    double getSugarLevel() const;

private:
    std::string name;
    int age;
    double bloodPressure; // mmHg
    double sugarLevel;    // mg/dL
};

#endif
