#include "Patient.hpp"

Patient::Patient(const std::string& name, int age, double bloodPressure, double sugarLevel)
    : name(name), age(age), bloodPressure(bloodPressure), sugarLevel(sugarLevel)
{

}

std::string Patient::getName() const
{
	return name;
}

std::string Patient::getHealthStatus() const
{
    if (bloodPressure > 140 || sugarLevel > 180)
    {
        return "Potential health issue detected.";
    }

    return "Patient is stable.";
}
