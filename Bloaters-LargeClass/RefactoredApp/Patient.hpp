#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>

class Patient {
private:
    std::string name;
    int age;
    bool hasInsurance;

public:
    Patient(const std::string& name, int age, bool insurance);

    void updateInfo(const std::string& newName, int newAge);

    std::string getName() const;
    int getAge() const;
    bool insuranceStatus() const;
};

#endif // PATIENT_HPP
