#include "PatientManagementSystem.hpp"

int main() {
    // Create a patient
    PatientManagementSystem patient("Alice Johnson", 45, true);

    // Update info
    patient.updatePatientInfo("Alice Johnson", 46);

    // Schedule appointments
    patient.scheduleAppointment("2025-09-15", "Smith");
    patient.scheduleAppointment("2025-09-22", "Taylor");

    // Add medical records
    patient.addMedicalRecord("Diabetes", "Insulin therapy");
    patient.addMedicalRecord("Flu", "Rest and fluids");

    // Billing
    patient.addCharge(300.0);
    patient.addCharge(150.0);
    patient.payBill(100.0);

    // Insurance
    patient.verifyInsurance();

    // Print details
    patient.printAppointments();
    patient.printMedicalHistory();
    std::cout << "Outstanding Bill: $" << patient.getOutstandingBill() << "\n";

    // Generate report file
    patient.generatePatientReport();

    return 0;
}



