#ifndef PMS_ROLE_H
#define PMS_ROLE_H

#include <string>

namespace pms
{
    class Role
    {
        public:
            Role();
            Role(std::string id);

            std::string GetId();
            void SetId(std::string id);

        protected:
            std::string id_;

    };
} // namespace pms

#endif // PMS_ROLE_H
