#include "Monitor.hpp"
#include "MockSensor.hpp"
#include "Patient.hpp"
#include "AlarmManager.hpp"
#include "AlarmPolicy.hpp"
#include "Logger.hpp"
#include "Types.hpp"
#include <memory>

int main()
{
    MonitorConfig cfg;
    Logger logger(cfg.logPath);
    AlarmPolicy policy(cfg.spo2Threshold, cfg.tempThreshold);
    AlarmManager alarmMgr(policy, logger, cfg.serverLogPath);
    auto sensor = std::make_unique<MockSensor>();
    Patient patient{"P123", "Alice", 45};
    Monitor monitor(std::move(sensor), patient, alarmMgr, logger, cfg);
    monitor.run(20);
    return 0;
}
