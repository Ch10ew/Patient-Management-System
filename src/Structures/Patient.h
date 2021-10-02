#ifndef PMS_PATIENT_H
#define PMS_PATIENT_H

#include "List.h"
#include "Role.h"
#include "Doctor.h"

#include <memory>

namespace pms
{
    /**
     * @brief `Visit` defines a `Patient`'s visit record.
     */
    struct Visit
    {
        Visit();
        Visit(
            std::string sickness,
            std::string description,
            time_t registration_time,
            std::shared_ptr<Doctor> doctor,
            std::string medicine_information
        );

        std::string sickness;
        std::string description;
        time_t registration_time;
        std::shared_ptr<Doctor> doctor;
        std::string medicine_information;
    };

    /**
     * @brief `VisitButForPrinting` defines a `Visit`, but its for printing.
     */
    struct VisitButForPrinting
    {
        VisitButForPrinting();
        VisitButForPrinting(
            std::string patient_id,
            std::string sickness,
            std::string description,
            time_t registration_time,
            std::shared_ptr<Doctor> doctor,
            std::string medicine_information
        );

        std::string patient_id;
        std::string sickness;
        std::string description;
        time_t registration_time;
        std::shared_ptr<Doctor> doctor;
        std::string medicine_information;
    };

    /**
     * @brief `Waiting` defines a record of a patient's visit.
     */
    struct Waiting
    {
        Waiting();
        Waiting(
            std::string id,
            std::string first_name,
            std::string last_name,
            int priorty,
            time_t registration_time
        );

        std::string id;
        std::string first_name;
        std::string last_name;
        int priority;
        time_t registration_time;
    };

    /**
     * @brief `Patient` defines a patient's profile.
     */
    class Patient : public Role
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
                std::string address,
                std::string disability,
                int priority
            );

        public:
            /**
             * @brief Overload for less than to compare by id.
             */
            inline bool operator<(const Patient& rhs) const { return this->id < rhs.id; };

        public:
            std::string first_name;
            std::string last_name;
            int age;
            char gender;
            std::string contact_number;
            std::string address;
            std::string disability;
            int priority;
            List<Visit> visit_history;
    };
} // namespace pms

#endif // PMS_PATIENT_H
