#ifndef REPORTGENERATOR_HPP
#define REPORTGENERATOR_HPP

#include <string>
#include <fstream>

class ReportGenerator {
public:
    void generate(const std::string& patientName,
                  int age,
                  double outstandingBill,
                  size_t appointments,
                  size_t records) const;
};

#endif // REPORTGENERATOR_HPP
