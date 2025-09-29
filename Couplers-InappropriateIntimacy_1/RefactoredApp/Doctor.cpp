#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

void Doctor::diagnose(const Patient& patient) const
{
    // ✅ Doctor no longer peeks at internals
    std::cout << "Doctor " << name
              << " diagnosing " << patient.getName() << "...\n";

    std::cout << patient.getHealthStatus() << "\n";
}
