#ifndef MEDICALHISTORY_HPP
#define MEDICALHISTORY_HPP

#include <string>
#include <vector>
#include <iostream>

struct MedicalRecord {
    std::string diagnosis;
    std::string treatment;
};

class MedicalHistory {
private:
    std::vector<MedicalRecord> records;

public:
    void addRecord(const std::string& diagnosis, const std::string& treatment);
    void printHistory(const std::string& patientName) const;
    size_t count() const;
};

#endif // MEDICALHISTORY_HPP
