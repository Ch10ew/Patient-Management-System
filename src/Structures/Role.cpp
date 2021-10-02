#include "Role.h"

#include <string>

namespace pms
{
    /**
     * @brief Default constructor. Does nothing.
     */
    Role::Role()
    {
    }
    
    /**
     * @brief Initializes id.
     * 
     * @param id Specified id.
     */
    Role::Role(std::string id)
    : id(id)
    {
    }

} // namespace pms
