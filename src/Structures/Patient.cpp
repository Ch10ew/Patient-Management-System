#include "Patient.h"

namespace pms
{
    std::string Patient::getFirstName()
    {
        return first_name_;
    }

    void Patient::setFirstName(std::string first_name)
    {
        first_name_ = first_name;
    }

    std::string Patient::getLastName()
    {
        return last_name_;
    }

    void Patient::setLastName(std::string last_name)
    {
        last_name_ = last_name;
    }

    int Patient::getAge()
    {
        return age_;
    }

    void Patient::setAge(int age)
    {
        age_ = age;
    }

    char Patient::getGender()
    {
        return gender_;
    }

    void Patient::setGender(char gender)
    {
        gender_ = gender;
    }

    std::string Patient::getContactNumber()
    {
        return contact_number_;
    }

    void Patient::setContactNumber(std::string contact_number)
    {
        contact_number_ = contact_number;
    }

    std::string Patient::getAddress()
    {
        return address_;
    }

    void Patient::setAddress(std::string address)
    {
        address_ = address;
    }

    std::string Patient::getSickness()
    {
        return sickness_;
    }

    void Patient::setSickness(std::string sickness)
    {
        sickness_ = sickness;
    }

    std::string Patient::getDescription()
    {
        return description_;
    }

    void Patient::setDescription(std::string description)
    {
        description_ = description;
    }

    std::string Patient::getCurrentVisitDate()
    {
        return current_visit_date_;
    }

    void Patient::setCurrentVisitDate(std::string current_visit_date)
    {
        current_visit_date_ = current_visit_date;
    }

    std::string Patient::getCurrentVisitTime()
    {
        return current_visit_time_;
    }

    void Patient::setCurrentVisitTime(std::string current_visit_time)
    {
        current_visit_time_ = current_visit_time;
    }

    Doctor Patient::getDoctor()
    {
        return doctor_;
    }

    void Patient::setDoctor(Doctor doctor)
    {
        doctor_ = doctor;
    }

    std::string Patient::getMedicineInformation()
    {
        return medicine_information_;
    }

    void Patient::setMedicineInformation(std::string medicine_information)
    {
        medicine_information_ = medicine_information;
    }

} // namespace pms