#include "LabTestReport.hpp"
#include <iostream>

LabTestReport::LabTestReport(const Patient& patient, const LabTest& test)
    : patient(patient), test(test) {}

void LabTestReport::printReport() const {
    std::cout << "Lab Test Report\n"
              << "Patient: " << patient.toString() << "\n"
              << "Test: " << test.toString() << "\n";
}
