#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(const std::string& name) : name(name)
{

}

void Doctor::diagnose(const Patient& patient) const
{
    // ❌ Inappropriate intimacy: Doctor knows too much about Patient internals
    double bp = patient.getBloodPressure();
    double sugar = patient.getSugarLevel();

    std::cout << "Doctor " << name << " diagnosing " << patient.getName() << "...\n";
    if (bp > 140 || sugar > 180)
    {
        std::cout << "Potential health issue detected.\n";
    }
    else
    {
        std::cout << "Patient is stable.\n";
    }
}
