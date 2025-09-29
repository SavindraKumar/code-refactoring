#include "Patient.hpp"

Patient::Patient(const std::string& name, int age, double bloodPressure, double sugarLevel)
    : name(name), age(age), bloodPressure(bloodPressure), sugarLevel(sugarLevel)
{

}

std::string Patient::getName() const
{
	return name;
}

int Patient::getAge() const
{
	return age;
}

double Patient::getBloodPressure() const
{
	return bloodPressure;
}

double Patient::getSugarLevel() const
{
	return sugarLevel;
}
