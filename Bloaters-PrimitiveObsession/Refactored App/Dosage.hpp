#ifndef DOSAGE_HPP
#define DOSAGE_HPP

#include <string>

class Dosage
{
private:
    double amount;     // e.g., 500
    std::string unit;  // e.g., "mg"

public:
    Dosage(double amount, const std::string& unit);
    std::string toString() const;
};

#endif // DOSAGE_HPP
