#include "../Application/Patient.hpp"

int main() {
    Address addr = {"123 Main St", "Apt 4B", "New York", "10001"};
    Insurance ins = {true, "HealthCare Inc.", "INS-98765"};

    // Much cleaner constructor call
    Patient p("Alice", "Brown", 32, "Female", addr, "555-1234", "alice@example.com", ins);

    p.printInfo();
    return 0;
}
