#ifndef DOCTOR_H
#define DOCTOR_H

#include "Patient.hpp"
#include <string>

class Doctor
{
public:
    Doctor(const std::string& name);
    void printBMI(const Patient& patient) const; // Delegates responsibility

private:
    std::string name;
};

#endif
