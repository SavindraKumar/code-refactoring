#ifndef INSURANCEVERIFIER_HPP
#define INSURANCEVERIFIER_HPP

#include <string>
#include <iostream>

class InsuranceVerifier {
public:
    void verify(const std::string& patientName, bool hasInsurance) const;
};

#endif // INSURANCEVERIFIER_HPP
