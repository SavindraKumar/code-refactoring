#include "ReportGenerator.hpp"

void ReportGenerator::generate(const std::string& patientName,
                               int age,
                               double outstandingBill,
                               size_t appointments,
                               size_t records) const {
    std::ofstream file(patientName + "_report.txt");
    file << "Patient: " << patientName << "\n";
    file << "Age: " << age << "\n";
    file << "Outstanding Bill: $" << outstandingBill << "\n";
    file << "Appointments: " << appointments << "\n";
    file << "Medical Records: " << records << "\n";
    file.close();
}
