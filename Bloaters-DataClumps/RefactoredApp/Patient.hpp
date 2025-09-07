#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

class Patient {
private:
    std::string name;
    int age;
    std::string gender;

public:
    Patient(const std::string& name, int age, const std::string& gender);
    std::string toString() const;
};

#endif // PATIENT_HPP
