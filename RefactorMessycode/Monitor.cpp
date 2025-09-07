#include "Monitor.hpp"
#include <thread>
#include <sstream>
#include <iostream>
#include <iomanip>

Monitor::Monitor(std::unique_ptr<ISensor> sensor,
        Patient patient,
        AlarmManager& alarmMgr,
        Logger& logger,
        MonitorConfig cfg)
  : sensor_(std::move(sensor)), patient_(std::move(patient)), alarmMgr_(alarmMgr), logger_(logger), cfg_(std::move(cfg))
{
}

void Monitor::run(int iterations)
{
    auto next = std::chrono::steady_clock::now();
    for (int i = 0; i < iterations; ++i)
    {
        next += cfg_.sampleInterval;
        VitalSigns v = sensor_->read();
        logStatus(v);
        bool critical = alarmMgr_.evaluateAndHandle(patient_.id(), patient_.name(), v);
        if (critical)
        {
            logger_.log("Critical condition for patient " + patient_.id());
        }
        std::this_thread::sleep_until(next);
    }
}

void Monitor::logStatus(const VitalSigns& v)
{
    std::ostringstream oss;
    oss << "STATUS patient=" << patient_.id()
        << " spo2=" << v.spo2
        << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
    logger_.log(oss.str());
    std::cout << "Patient " << patient_.name() << " Age:" << patient_.age() << "\n";
    std::cout << "SpO2=" << v.spo2 << "%  Temp=" << v.tempC << "C\n";
}
