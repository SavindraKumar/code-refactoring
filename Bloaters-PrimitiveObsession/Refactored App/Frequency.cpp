#include "Frequency.hpp"
#include <sstream>

Frequency::Frequency(int timesPerDay)
    : timesPerDay(timesPerDay)
{}

std::string Frequency::toString() const {
    std::ostringstream oss;
    oss << timesPerDay << " times a day";
    return oss.str();
}
