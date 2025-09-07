#include"HospitalSystem.hpp"

int main()
{
    // Create a sample patient
    Patient patient;
    patient.name = "John Doe";
    patient.age = 65;
    patient.hasInsurance = true;

    // Create hospital system
    HospitalSystem hospital;

    try
    {
        // Process patient record (long method smell)
        hospital.processPatientRecord(patient);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error processing patient: " << e.what() << std::endl;
    }

    return 0;
}

