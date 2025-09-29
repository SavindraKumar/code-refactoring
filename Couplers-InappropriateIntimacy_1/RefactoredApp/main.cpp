#include "Doctor.hpp"
#include "Patient.hpp"

int main()
{
    Patient patient("Alice", 45, 150, 190);
    Doctor doctor("Dr. Smith");

    doctor.diagnose(patient);
    return 0;
}
