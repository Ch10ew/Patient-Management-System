#include "Role.h"

namespace pms
{
    Role::Role()
    {
    }
    
    Role::Role(std::string id)
    : id_(id)
    {
    }

    std::string Role::GetId()
    {
        return id_;
    }
    
    void Role::SetId(std::string id)
    {
        id_ = id;
    }

} // namespace pms
