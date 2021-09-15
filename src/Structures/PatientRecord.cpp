#include "PatientRecord.h"

namespace pms
{
    std::string PatientRecord::getFirstName()
    {
        return first_name_;
    }

    void PatientRecord::setFirstName(std::string first_name)
    {
        first_name_ = first_name;
    }

    std::string PatientRecord::getLastName()
    {
        return last_name_;
    }

    void PatientRecord::setLastName(std::string last_name)
    {
        last_name_ = last_name;
    }

    int PatientRecord::getAge()
    {
        return age_;
    }

    void PatientRecord::setAge(int age)
    {
        age_ = age;
    }

    char PatientRecord::getGender()
    {
        return gender_;
    }

    void PatientRecord::setGender(char gender)
    {
        gender_ = gender;
    }

    std::string PatientRecord::getContactNumber()
    {
        return contact_number_;
    }

    void PatientRecord::setContactNumber(std::string contact_number)
    {
        contact_number_ = contact_number;
    }

    std::string PatientRecord::getAddress()
    {
        return address_;
    }

    void PatientRecord::setAddress(std::string address)
    {
        address_ = address;
    }

    std::string PatientRecord::getSickness()
    {
        return sickness_;
    }

    void PatientRecord::setSickness(std::string sickness)
    {
        sickness_ = sickness;
    }

    std::string PatientRecord::getDescription()
    {
        return description_;
    }

    void PatientRecord::setDescription(std::string description)
    {
        description_ = description;
    }

    std::string PatientRecord::getCurrentVisitDate()
    {
        return current_visit_date_;
    }

    void PatientRecord::setCurrentVisitDate(std::string current_visit_date)
    {
        current_visit_date_ = current_visit_date;
    }

    std::string PatientRecord::getCurrentVisitTime()
    {
        return current_visit_time_;
    }

    void PatientRecord::setCurrentVisitTime(std::string current_visit_time)
    {
        current_visit_time_ = current_visit_time;
    }

    Doctor PatientRecord::getDoctor()
    {
        return doctor_;
    }

    void PatientRecord::setDoctor(Doctor doctor)
    {
        doctor_ = doctor;
    }

    std::string PatientRecord::getMedicineInformation()
    {
        return medicine_information_;
    }

    void PatientRecord::setMedicineInformation(std::string medicine_information)
    {
        medicine_information_ = medicine_information;
    }

} // namespace pms