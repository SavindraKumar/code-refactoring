#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

void Doctor::reviewPatientHistory(const Patient& patient) const
{
    // ✅ Doctor no longer touches private fields
    std::cout << "Doctor " << name
              << " reviewing " << patient.getName()
              << "'s medical history: "
              << patient.getMedicalHistorySummary() << "\n";
}
