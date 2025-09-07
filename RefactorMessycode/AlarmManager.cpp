#include "AlarmManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

AlarmManager::AlarmManager(const AlarmPolicy& policy, Logger& logger, const std::string& serverPath)
  : policy_(policy), logger_(logger), serverPath_(serverPath)
{
}

bool AlarmManager::evaluateAndHandle(const std::string& patientId, const std::string& patientName, const VitalSigns& v)
{
    bool escalated = false;
    if (policy_.lowSpO2(v.spo2))
    {
        std::ostringstream oss;
        oss << "ALARM LOW_SPO2 patient=" << patientId << " name=" << patientName << " spo2=" << v.spo2;
        logger_.log(oss.str());
        std::cout << "Alarm: Low SpO2 for " << patientName << " (" << v.spo2 << "%)\n";
        if (v.spo2 < 80)
        {
            escalate(oss.str());
            escalated = true;
        }
    }
    if (policy_.highTemp(v.tempC))
    {
        std::ostringstream oss;
        oss << "ALARM HIGH_TEMP patient=" << patientId << " temp=" << std::fixed << std::setprecision(1) << v.tempC;
        logger_.log(oss.str());
        std::cout << "Alarm: High Temp for " << patientName << " (" << v.tempC << "C)\n";
    }
    return escalated;
}

void AlarmManager::escalate(const std::string& message)
{
    std::ofstream ofs(serverPath_, std::ios::app);
    if (ofs)
    {
        ofs << message << "\n";
        ofs.flush();
    }
    logger_.log("ESCALATION SENT: " + message);
    std::cout << "Escalation sent to server: " << message << "\n";
}
