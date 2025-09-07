#ifndef APPLICATION_HOSPITALSYSTEM_HPP_
#define APPLICATION_HOSPITALSYSTEM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Patient
{
    std::string name;
    int age;
    std::string diagnosis;
    std::vector<std::string> medications;
    bool hasInsurance;
    double treatmentCost;
};

class HospitalSystem
{
public:
    void processPatientRecord(Patient& patient);

};

#endif /* APPLICATION_HOSPITALSYSTEM_HPP_ */
