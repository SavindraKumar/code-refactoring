#include "LabTestReport.hpp"
#include <iostream>

int main() {
    Patient patient("Alice Brown", 35, "Female");
    LabTest test("Blood Test", "2025-09-06", "Normal");

    LabTestReport report(patient, test);
    report.printReport();

    return 0;
}
