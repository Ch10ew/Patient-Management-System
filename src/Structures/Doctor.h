#ifndef PMS_DOCTOR_H
#define PMS_DOCTOR_H

#include "Role.h"
#include <string>

namespace pms
{
    class Doctor : protected Role
    {
        private:
            std::string username;
            std::string password;
            std::string first_name_;
            std::string last_name_;
    };
} // namespace pms

#endif // PMS_DOCTOR_H
