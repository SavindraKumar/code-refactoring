#include "LabTest.hpp"
#include <iostream>

int main() {
    std::cout << "Test: " << LabTest::getTestName()
              << " (" << LabTest::getTestUnit() << ")" << std::endl;

    return 0;
}
