#include "Prescription.hpp"

int main() {
    // Using raw strings for everything (Primitive Obsession Bloater!)
    Prescription p("John Doe", "Dr. Smith", "Amoxicillin", "500mg", "Twice a day", "10 days");

    p.print();
    return 0;
}
