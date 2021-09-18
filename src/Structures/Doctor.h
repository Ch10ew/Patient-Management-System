#ifndef PMS_DOCTOR_H
#define PMS_DOCTOR_H

#include "Role.h"
#include <string>

namespace pms
{
    class Doctor : public Role
    {
        public:
            Doctor();
            Doctor(std::string id);
            Doctor(
                std::string id,
                std::string username,
                std::string password,
                std::string first_name,
                std::string last_name,
                std::string specialism
            );

        public:
            std::string username;
            std::string password;
            std::string first_name;
            std::string last_name;
            std::string specialism;
    };
} // namespace pms

#endif // PMS_DOCTOR_H
