#include "MedicalHistory.hpp"

void MedicalHistory::addRecord(const std::string& diagnosis, const std::string& treatment) {
    records.push_back({diagnosis, treatment});
}

void MedicalHistory::printHistory(const std::string& patientName) const {
    std::cout << "Medical history for " << patientName << ":\n";
    for (const auto& rec : records) {
        std::cout << " - " << rec.diagnosis << " treated with " << rec.treatment << "\n";
    }
}

size_t MedicalHistory::count() const {
    return records.size();
}
