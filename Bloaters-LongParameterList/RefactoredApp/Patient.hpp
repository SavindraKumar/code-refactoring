#ifndef PATIENT_HPP
#define PATIENT_HPP

#include <string>
#include <iostream>

struct Address {
    std::string line1;
    std::string line2;
    std::string city;
    std::string postalCode;
};

struct Insurance {
    bool hasInsurance;
    std::string provider;
    std::string insuranceId;
};

struct PatientInfo {
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    std::string phone;
    std::string email;
};

class Patient {
private:
    PatientInfo info;
    Address address;
    Insurance insurance;

public:
    Patient(const PatientInfo& info,
            const Address& address,
            const Insurance& insurance);
    void printInfo() const;
};

#endif // PATIENT_HPP