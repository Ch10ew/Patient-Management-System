#ifndef PMS_PATIENT_H
#define PMS_PATIENT_H

#include "Role.h"
#include "Doctor.h"

namespace pms
{
    class Patient : protected Role
    {
        private:
            std::string first_name_;
            std::string last_name_;
            int age_;
            char gender_;
            std::string contact_number_;
            std::string address_;
            std::string sickness_;
            std::string description_;
            List<>
            std::string disability_;
            Doctor doctor_name_;
            std::string medicine_information_;
    };
} // namespace pms

#endif // PMS_PATIENT_H
