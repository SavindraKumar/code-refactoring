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

class Patient {
private:
    std::string firstName;
    std::string lastName;
    int age;
    std::string gender;
    Address address;
    std::string phone;
    std::string email;
    Insurance insurance;

public:
    // Cleaner constructor
    Patient(const std::string& firstName,
            const std::string& lastName,
            int age,
            const std::string& gender,
            const Address& address,
            const std::string& phone,
            const std::string& email,
            const Insurance& insurance);

    void printInfo() const;
};

#endif // PATIENT_HPP
