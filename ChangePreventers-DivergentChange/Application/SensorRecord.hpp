#pragma once
#include <string>
#include <iostream>

class SensorRecord
{
private:
    std::string sensorId;
    double voltage;
    double current;

public:
    SensorRecord(const std::string& id, double v, double c);

    void saveToDatabase();
    void displayUI();
    void calculatePower();
};
