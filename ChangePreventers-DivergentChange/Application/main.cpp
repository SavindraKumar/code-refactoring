#include "SensorRecord.hpp"

int main()
{
    SensorRecord rec("SENSOR-1", 230.0, 5.0);
    rec.saveToDatabase();
    rec.displayUI();
    rec.calculatePower();
    return 0;
}
