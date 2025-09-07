#include "Patient.hpp"

Patient::Patient(std::string id, std::string name, int age)
    : id_(std::move(id)), name_(std::move(name)), age_(age)
{
}

const std::string& Patient::id() const
{
    return id_;
}

const std::string& Patient::name() const
{
    return name_;
}

int Patient::age() const
{
    return age_;
}
