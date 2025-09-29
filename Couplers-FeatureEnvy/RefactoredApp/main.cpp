#include "Doctor.hpp"
#include "Patient.hpp"

int main()
{
    Patient patient("Alice", 30, 70.0, 1.75);
    Doctor doctor("Dr. Smith");

    doctor.printBMI(patient);
    return 0;
}
