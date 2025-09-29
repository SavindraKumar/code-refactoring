#include "Patient.hpp"

Patient::Patient(const PatientInfo& info,
                 const Address& address,
                 const Insurance& insurance)
    : info(info),
      address(address),
      insurance(insurance)
{

}

void Patient::printInfo() const {
    std::cout << "Patient: " << info.firstName << " " << info.lastName << " (" << info.age << ", " << info.gender << ")\n"
              << "Address: " << address.line1 << ", " << address.line2 << ", " << address.city << ", " << address.postalCode << "\n"
              << "Phone: " << info.phone << ", Email: " << info.email << "\n";
    if (insurance.hasInsurance) {
        std::cout << "Insurance: " << insurance.provider << " (ID: " << insurance.insuranceId << ")\n";
    } else {
        std::cout << "No insurance.\n";
    }
}
