#include "../Application/Patient.hpp"

Patient::Patient(const std::string& firstName,
                 const std::string& lastName,
                 int age,
                 const std::string& gender,
                 const Address& address,
                 const std::string& phone,
                 const std::string& email,
                 const Insurance& insurance)
    : firstName(firstName),
      lastName(lastName),
      age(age),
      gender(gender),
      address(address),
      phone(phone),
      email(email),
      insurance(insurance) {}

void Patient::printInfo() const {
    std::cout << "Patient: " << firstName << " " << lastName << " (" << age << ", " << gender << ")\n"
              << "Address: " << address.line1 << ", " << address.line2 << ", " << address.city << ", " << address.postalCode << "\n"
              << "Phone: " << phone << ", Email: " << email << "\n";
    if (insurance.hasInsurance) {
        std::cout << "Insurance: " << insurance.provider << " (ID: " << insurance.insuranceId << ")\n";
    } else {
        std::cout << "No insurance.\n";
    }
}
