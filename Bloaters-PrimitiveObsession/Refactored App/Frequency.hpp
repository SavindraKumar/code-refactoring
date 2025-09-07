#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <string>

class Frequency
{
private:
    int timesPerDay;

public:
    Frequency(int timesPerDay);
    std::string toString() const;
};

#endif // FREQUENCY_HPP
