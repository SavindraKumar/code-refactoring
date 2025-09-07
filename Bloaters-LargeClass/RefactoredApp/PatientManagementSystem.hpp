#ifndef PATIENTMANAGEMENTSYSTEM_HPP
#define PATIENTMANAGEMENTSYSTEM_HPP

#include "Patient.hpp"
#include "AppointmentScheduler.hpp"
#include "MedicalHistory.hpp"
#include "BillingSystem.hpp"
#include "InsuranceVerifier.hpp"
#include "ReportGenerator.hpp"

class PatientManagementSystem {
private:
    Patient patient;

public:
    AppointmentScheduler scheduler;
    MedicalHistory history;
    BillingSystem billing;
    InsuranceVerifier insuranceVerifier;
    ReportGenerator reportGenerator;

    PatientManagementSystem(const std::string& name, int age, bool insurance);

    Patient& getPatient();
    const Patient& getPatient() const;
};

#endif // PATIENTMANAGEMENTSYSTEM_HPP
