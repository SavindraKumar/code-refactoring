#include "Patient.hpp"

Patient::Patient(const std::string& name, const std::string& history)
    : name(name), medicalHistory(history)
{

}

std::string Patient::getName() const
{
    return name;
}

std::string Patient::getMedicalHistorySummary() const
{
    // Only share part of the history (not full details)
    return "Summary: " + medicalHistory.substr(0, 20) + "...";
}
