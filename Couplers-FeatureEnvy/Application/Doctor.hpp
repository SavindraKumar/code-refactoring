#ifndef DOCTOR_H
#define DOCTOR_H

#include "Patient.hpp"
#include <string>

class Doctor
{
public:
    Doctor(const std::string& name);
    double calculateBMI(const Patient& patient) const; // Feature Envy
    void printBMI(const Patient& patient) const;

private:
    std::string name;
};

#endif
