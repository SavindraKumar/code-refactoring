#include "LabTestReport.hpp"

int main() {
    // Repetition of patient data and test data (data clumps!)
    LabTestReport report("Alice Brown", 35, "Female", "Blood Test", "2025-09-06", "Normal");
    report.printReport();

    return 0;
}
