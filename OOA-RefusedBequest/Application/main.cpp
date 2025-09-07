#include "Thermometer.hpp"

int main()
{
    Thermometer t("THERMO-101");
    t.start();
    t.calibrate();
    t.stop();

    return 0;
}
