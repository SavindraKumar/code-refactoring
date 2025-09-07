#include "PatientManagementSystem.hpp"
#include <iostream>

int main() {
    // Create the system
    PatientManagementSystem system("Alice Johnson", 45, true);

    // Update patient info
    system.getPatient().updateInfo("Alice Johnson", 46);

    // Schedule appointments
    system.scheduler.scheduleAppointment("2025-09-15", "Smith");
    system.scheduler.scheduleAppointment("2025-09-22", "Taylor");
    system.scheduler.printAppointments(system.getPatient().getName());

    // Medical history
    system.history.addRecord("Diabetes", "Insulin therapy");
    system.history.addRecord("Flu", "Rest and fluids");
    system.history.printHistory(system.getPatient().getName());

    // Billing
    system.billing.addCharge(300.0);
    system.billing.addCharge(150.0);
    system.billing.payBill(100.0);
    std::cout << "Outstanding Bill: $" << system.billing.getOutstandingBill() << "\n";

    // Insurance verification
    system.insuranceVerifier.verify(system.getPatient().getName(), system.getPatient().insuranceStatus());

    // Report generation
    system.reportGenerator.generate(system.getPatient().getName(),
                                    system.getPatient().getAge(),
                                    system.billing.getOutstandingBill(),
                                    system.scheduler.count(),
                                    system.history.count());

    return 0;
}
