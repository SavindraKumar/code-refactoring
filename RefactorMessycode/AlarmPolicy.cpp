#include "AlarmPolicy.hpp"

AlarmPolicy::AlarmPolicy(int spo2Th, double tempTh) : spo2Th_(spo2Th), tempTh_(tempTh)
{

}

bool AlarmPolicy::lowSpO2(int spo2) const
{
    return spo2 < spo2Th_;
}

bool AlarmPolicy::highTemp(double t) const
{
    return t > tempTh_;
}
