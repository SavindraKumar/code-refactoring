#include "PatientManagementSystem.hpp"

PatientManagementSystem::PatientManagementSystem(const std::string& name, int age, bool insurance)
    : patient(name, age, insurance) {}

Patient& PatientManagementSystem::getPatient() {
    return patient;
}

const Patient& PatientManagementSystem::getPatient() const {
    return patient;
}
