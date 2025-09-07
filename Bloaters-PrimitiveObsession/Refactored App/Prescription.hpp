#ifndef PRESCRIPTION_HPP
#define PRESCRIPTION_HPP

#include <string>
#include "Dosage.hpp"
#include "Frequency.hpp"
#include "Duration.hpp"

class Prescription {
private:
    std::string patientName;
    std::string doctorName;
    std::string medicationName;
    Dosage dosage;
    Frequency frequency;
    Duration duration;

public:
    Prescription(const std::string& patientName,
                 const std::string& doctorName,
                 const std::string& medicationName,
                 const Dosage& dosage,
                 const Frequency& frequency,
                 const Duration& duration);

    void print() const;
};

#endif // PRESCRIPTION_HPP
