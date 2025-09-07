#include "LabTest.hpp"
#include <sstream>

LabTest::LabTest(const std::string& testName,
                 const std::string& date,
                 const std::string& result)
    : testName(testName), date(date), result(result) {}

std::string LabTest::toString() const {
    std::ostringstream oss;
    oss << testName << " on " << date << " → " << result;
    return oss.str();
}
