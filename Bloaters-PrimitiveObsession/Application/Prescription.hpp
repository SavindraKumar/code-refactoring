#ifndef PRESCRIPTION_HPP
#define PRESCRIPTION_HPP

#include <string>

class Prescription {
private:
    std::string patientName;
    std::string doctorName;
    std::string medicationName;
    std::string dosage;    // e.g., "500mg"
    std::string frequency; // e.g., "Twice a day"
    std::string duration;  // e.g., "10 days"

public:
    Prescription(const std::string& patientName,
                 const std::string& doctorName,
                 const std::string& medicationName,
                 const std::string& dosage,
                 const std::string& frequency,
                 const std::string& duration);

    void print() const;
};

#endif // PRESCRIPTION_HPP
