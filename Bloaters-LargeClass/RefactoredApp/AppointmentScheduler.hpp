#ifndef APPOINTMENTSCHEDULER_HPP
#define APPOINTMENTSCHEDULER_HPP

#include <string>
#include <vector>
#include <iostream>

struct Appointment {
    std::string date;
    std::string doctor;
};

class AppointmentScheduler {
private:
    std::vector<Appointment> appointments;

public:
    void scheduleAppointment(const std::string& date, const std::string& doctor);
    void printAppointments(const std::string& patientName) const;
    size_t count() const;
};

#endif // APPOINTMENTSCHEDULER_HPP
