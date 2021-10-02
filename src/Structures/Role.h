#ifndef PMS_ROLE_H
#define PMS_ROLE_H

#include <string>

namespace pms
{
    /**
     * @brief `Role` defines an entity with an id.
     */
    class Role
    {
        public:
            Role();
            Role(std::string id);

        public:
            std::string id;
    };
} // namespace pms

#endif // PMS_ROLE_H
