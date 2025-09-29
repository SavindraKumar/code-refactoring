#ifndef DOCTOR_H
#define DOCTOR_H

#include "Patient.hpp"
#include <string>

class Doctor
{
public:
    Doctor(const std::string& name);
    void reviewPatientHistory(const Patient& patient) const;

private:
    std::string name;
};

#endif
