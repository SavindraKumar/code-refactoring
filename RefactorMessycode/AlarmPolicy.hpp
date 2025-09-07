#ifndef ALARMPOLICY_HPP
#define ALARMPOLICY_HPP
/**
 * @brief Alarm policy for threshold logic.
 */
class AlarmPolicy
{
public:
    /**
     * @brief Construct with thresholds.
     * @param spo2Th SpO2 threshold
     * @param tempTh Temperature threshold
     */
    explicit AlarmPolicy(int spo2Th, double tempTh);
    /**
     * @brief Check if SpO2 is low.
     * @param spo2 SpO2 value
     * @return true if below threshold
     */
    bool lowSpO2(int spo2) const;
    /**
     * @brief Check if temperature is high.
     * @param t Temperature value
     * @return true if above threshold
     */
    bool highTemp(double t) const;
private:
    int spo2Th_;
    double tempTh_;
};
#endif // ALARMPOLICY_HPP
