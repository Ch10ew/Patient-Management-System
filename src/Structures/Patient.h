#ifndef PMS_PATIENT_H
#define PMS_PATIENT_H

#include "List.h"
#include "Role.h"
#include "Doctor.h"

#include <memory>

namespace pms
{
    struct Visit
    {
        std::string sickness;
        std::string description;
        std::string current_visit_date; // Change to ctime wrapper when done
        std::string current_visit_time;
        std::string disability;
        std::shared_ptr<Doctor> doctor;
        std::string medicine_information;
    };

    class Patient : protected Role
    {
        public:
            Patient();
            Patient(std::string id);
            Patient(
                std::string id,
                std::string first_name,
                std::string last_name,
                int age,
                char gender,
                std::string contact_number,
                std::string address
            );

        public:
            std::string first_name;
            std::string last_name;
            int age;
            char gender;
            std::string contact_number;
            std::string address;
            List<Visit> visit_history;
    };
} // namespace pms

#endif // PMS_PATIENT_H
