#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

void Doctor::printBMI(const Patient& patient) const
{
    std::cout << "Doctor " << name
              << " reports BMI of " << patient.getName()
              << " is " << patient.calculateBMI() << "\n";
}
