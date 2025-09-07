#include "Duration.hpp"
#include <sstream>

Duration::Duration(int days)
    : days(days) {}

std::string Duration::toString() const {
    std::ostringstream oss;
    oss << days << " days";
    return oss.str();
}
