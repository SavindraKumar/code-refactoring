#ifndef PATIENT_HPP
#define PATIENT_HPP
#include <string>
/**
 * @brief Patient value object.
 */
class Patient
{
public:
    /**
     * @brief Construct a patient.
     * @param id Patient ID
     * @param name Patient name
     * @param age Patient age
     */
    Patient(std::string id, std::string name, int age);
    /** @brief Get patient ID. */
    const std::string& id() const;
    /** @brief Get patient name. */
    const std::string& name() const;
    /** @brief Get patient age. */
    int age() const;
private:
    std::string id_;
    std::string name_;
    int age_;
};
#endif // PATIENT_HPP
