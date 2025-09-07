#include "AppointmentScheduler.hpp"

void AppointmentScheduler::scheduleAppointment(const std::string& date, const std::string& doctor)
{
    appointments.push_back({date, doctor});
}

void AppointmentScheduler::printAppointments(const std::string& patientName) const
{
    std::cout << "Appointments for " << patientName << ":\n";

    for (const auto& appt : appointments)
    {
        std::cout << " - " << appt.date << " with Dr. " << appt.doctor << "\n";
    }
}

size_t AppointmentScheduler::count() const
{
    return appointments.size();
}
