#ifndef LABTEST_HPP
#define LABTEST_HPP

#include <string>

class LabTest {
private:
    std::string testName;
    std::string date;
    std::string result;

public:
    LabTest(const std::string& testName,
            const std::string& date,
            const std::string& result);

    std::string toString() const;
};

#endif // LABTEST_HPP
