#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient
{
public:
    Patient(const std::string& name, int age, double weight, double height);

    std::string getName() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

private:
    std::string name;
    int age;
    double weight; // in kg
    double height; // in meters
};

#endif
