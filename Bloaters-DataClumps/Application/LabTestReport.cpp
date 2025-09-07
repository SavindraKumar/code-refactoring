#include "LabTestReport.hpp"
#include <iostream>

LabTestReport::LabTestReport(const std::string& patientName,
                             int patientAge,
                             const std::string& patientGender,
                             const std::string& testName,
                             const std::string& testDate,
                             const std::string& result)
    : patientName(patientName),
      patientAge(patientAge),
      patientGender(patientGender),
      testName(testName),
      testDate(testDate),
      result(result) {}

void LabTestReport::printReport() const {
    std::cout << "Lab Test Report\n"
              << "Patient: " << patientName << " (" << patientAge << ", " << patientGender << ")\n"
              << "Test: " << testName << " on " << testDate << "\n"
              << "Result: " << result << "\n";
}
