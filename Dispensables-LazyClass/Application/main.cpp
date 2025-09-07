#include "LabTestHelper.hpp"
#include <iostream>

int main() {
    LabTestHelper helper;

    std::cout << "Test: " << helper.getTestName()
              << " (" << helper.getTestUnit() << ")" << std::endl;

    return 0;
}
