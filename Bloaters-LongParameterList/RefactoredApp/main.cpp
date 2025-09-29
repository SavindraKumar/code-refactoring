#include "../RefactoredApp/Patient.hpp"

int main() {
    Address addr = {"123 Main St", "Apt 4B", "New York", "10001"};
    Insurance ins = {true, "HealthCare Inc.", "INS-98765"};
    PatientInfo info = {"Alice", "Brown", 32, "Female", "555-1234", "alice@example.com"};

    Patient p(info, addr, ins);

    p.printInfo();
    return 0;
}