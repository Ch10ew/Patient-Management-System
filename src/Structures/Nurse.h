#ifndef PMS_NURSE_H
#define PMS_NURSE_H

#include "Role.h"
#include <string>

namespace pms
{
    class Nurse : protected Role
    {
        public:
            Nurse();
            Nurse(std::string id);
            Nurse(
                std::string id,
                std::string username,
                std::string password,
                std::string first_name,
                std::string last_name
            );

        public:
            std::string username;
            std::string password;
            std::string first_name;
            std::string last_name;
    };
} // namespace pms

#endif // PMS_NURSE_H
