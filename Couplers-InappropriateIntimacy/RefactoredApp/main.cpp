#include "Doctor.hpp"
#include "Patient.hpp"

int main()
{
    Patient patient("Alice", "Diabetes Type II, Hypertension, Allergy: Penicillin");
    Doctor doctor("Dr. Smith");

    doctor.reviewPatientHistory(patient);
    return 0;
}
