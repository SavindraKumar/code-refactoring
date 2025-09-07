#include"HospitalSystem.hpp"

void HospitalSystem::processPatientRecord(Patient& patient)
{
    validatePatientData(patient);
    assignDiagnosis(patient);
    prescribeMedication(patient);
    calculateBilling(patient);
    saveToDatabase(patient);
    printReport(patient);
}

void HospitalSystem::validatePatientData(const Patient& patient)
{
    if (patient.name.empty())
    {
        throw std::runtime_error("Patient name is missing");
    }
    if (patient.age <= 0)
    {
        throw std::runtime_error("Invalid patient age");
    }
}

void HospitalSystem::assignDiagnosis(Patient& patient)
{
    if (patient.age > 60)
    {
        patient.diagnosis = "High risk of hypertension";
    }
    else
    {
        patient.diagnosis = "Routine checkup required";
    }
}

void HospitalSystem::prescribeMedication(Patient& patient)
{
    if (patient.diagnosis.find("hypertension") != std::string::npos)
    {
        patient.medications.push_back("Blood pressure medication");
    }
    else
    {
        patient.medications.push_back("Vitamin supplements");
    }
}

void HospitalSystem::calculateBilling(Patient& patient)
{
    if (patient.hasInsurance)
    {
        patient.treatmentCost = 200.0; // discounted flat rate
    }
    else
    {
        patient.treatmentCost = 500.0; // full charge
    }
}

void HospitalSystem::saveToDatabase(const Patient& patient)
{
    std::ofstream db("patients.txt", std::ios::app);
    db << patient.name << "," << patient.age << ","
       << patient.diagnosis << "," << patient.treatmentCost << "\n";
}

void HospitalSystem::printReport(const Patient& patient)
{
    std::cout << "Patient: " << patient.name << "\n"
              << "Diagnosis: " << patient.diagnosis << "\n"
              << "Medications: ";
    for (const auto& med : patient.medications) {
        std::cout << med << " ";
    }
    std::cout << "\n"
              << "Bill: $" << patient.treatmentCost << "\n"
              << "--------------------------------------\n";
}
