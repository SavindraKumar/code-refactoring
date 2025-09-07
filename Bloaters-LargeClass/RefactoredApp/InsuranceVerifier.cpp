#include "InsuranceVerifier.hpp"

void InsuranceVerifier::verify(const std::string& patientName, bool hasInsurance) const {
    if (hasInsurance) {
        std::cout << "Insurance verified for " << patientName << "\n";
    } else {
        std::cout << patientName << " has no insurance.\n";
    }
}
