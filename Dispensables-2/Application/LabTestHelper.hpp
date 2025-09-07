#ifndef LABTESTHELPER_HPP
#define LABTESTHELPER_HPP

#include <string>

class LabTestHelper {
public:
    LabTestHelper();

    std::string getTestName() const;
    std::string getTestUnit() const;
};

#endif // LABTESTHELPER_HPP
