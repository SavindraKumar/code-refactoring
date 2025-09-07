#ifndef DURATION_HPP
#define DURATION_HPP

#include <string>

class Duration {
private:
    int days;

public:
    Duration(int days);
    std::string toString() const;
};

#endif // DURATION_HPP
