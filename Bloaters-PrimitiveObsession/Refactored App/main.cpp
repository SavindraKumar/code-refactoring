#include "Prescription.hpp"
#include <iostream>

int main() {
    Dosage d(500, "mg");
    Frequency f(2);      // twice a day
    Duration du(10);     // for 10 days

    Prescription p("John Doe", "Dr. Smith", "Amoxicillin", d, f, du);
    p.print();

    return 0;
}
