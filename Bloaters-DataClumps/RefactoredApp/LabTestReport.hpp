#ifndef LABTESTREPORT_HPP
#define LABTESTREPORT_HPP

#include "Patient.hpp"
#include "LabTest.hpp"

class LabTestReport {
private:
    Patient patient;
    LabTest test;

public:
    LabTestReport(const Patient& patient, const LabTest& test);
    void printReport() const;
};

#endif // LABTESTREPORT_HPP
