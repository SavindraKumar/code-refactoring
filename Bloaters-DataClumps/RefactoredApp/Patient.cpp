#include "Patient.hpp"
#include <sstream>

Patient::Patient(const std::string& name, int age, const std::string& gender)
    : name(name), age(age), gender(gender) {}

std::string Patient::toString() const {
    std::ostringstream oss;
    oss << name << " (" << age << ", " << gender << ")";
    return oss.str();
}
