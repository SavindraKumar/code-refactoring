#include "Doctor.hp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

double Doctor::calculateBMI(const Patient& patient) const
{
    // Doctor pokes into Patient's internals (Feature Envy)
    return patient.getWeight() / (patient.getHeight() * patient.getHeight());
}

void Doctor::printBMI(const Patient& patient) const
{
    std::cout << "Doctor " << name
              << " reports BMI of " << patient.getName()
              << " is " << calculateBMI(patient) << "\n";
}
