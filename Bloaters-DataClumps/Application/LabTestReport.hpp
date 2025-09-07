#ifndef LABTESTREPORT_HPP
#define LABTESTREPORT_HPP

#include <string>

class LabTestReport
{
private:
    std::string patientName;
    int patientAge;
    std::string patientGender;

    std::string testName;
    std::string testDate;
    std::string result;

public:
    LabTestReport(const std::string& patientName,
                  int patientAge,
                  const std::string& patientGender,
                  const std::string& testName,
                  const std::string& testDate,
                  const std::string& result);

    void printReport() const;
};

#endif // LABTESTREPORT_HPP
