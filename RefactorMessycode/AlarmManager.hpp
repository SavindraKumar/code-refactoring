#ifndef ALARMMANAGER_HPP
#define ALARMMANAGER_HPP
#include "AlarmPolicy.hpp"
#include "Logger.hpp"
#include <string>
#include "Types.hpp"
/**
 * @brief Manages alarm reactions and escalation.
 */
class AlarmManager
{
public:
    /**
     * @brief Construct with policy, logger, and server path.
     */
    AlarmManager(const AlarmPolicy& policy, Logger& logger, const std::string& serverPath);
    /**
     * @brief Evaluate and handle alarm conditions.
     * @param patientId Patient ID
     * @param patientName Patient name
     * @param v Vital signs
     * @return true if critical escalation occurred
     */
    bool evaluateAndHandle(const std::string& patientId, const std::string& patientName, const VitalSigns& v);
private:
    void escalate(const std::string& message);
    const AlarmPolicy& policy_;
    Logger& logger_;
    std::string serverPath_;
};
#endif // ALARMMANAGER_HPP
