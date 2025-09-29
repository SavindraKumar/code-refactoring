#include "Patient.hpp"

Patient::Patient(const std::string& name, int age, double weight, double height)
    : name(name), age(age), weight(weight), height(height)
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

double Patient::getWeight() const
{
	return weight;
}

double Patient::getHeight() const
{
	return height;
}
