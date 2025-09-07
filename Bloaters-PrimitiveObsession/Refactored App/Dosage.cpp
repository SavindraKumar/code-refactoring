#include "Dosage.hpp"
#include <sstream>

Dosage::Dosage(double amount, const std::string& unit)
    : amount(amount), unit(unit) {}

std::string Dosage::toString() const {
    std::ostringstream oss;
    oss << amount << unit;
    return oss.str();
}
