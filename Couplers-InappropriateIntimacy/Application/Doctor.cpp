#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

void Doctor::reviewPatientHistory(const Patient& patient) const
{
    // ❌ Doctor directly accesses private field (due to 'friend')
    std::cout << "Doctor " << name << " reviewing history: "
              << patient.medicalHistory << "\n";
}
