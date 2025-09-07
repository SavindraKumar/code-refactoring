#include "Patient.hpp"

Patient::Patient(const std::string& name, int age, bool insurance)
    : name(name), age(age), hasInsurance(insurance) {}

void Patient::updateInfo(const std::string& newName, int newAge) {
    name = newName;
    age = newAge;
}

std::string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
bool Patient::insuranceStatus() const { return hasInsurance; }
