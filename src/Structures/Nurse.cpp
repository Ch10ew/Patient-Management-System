#include "Nurse.h"

#include <string>

namespace pms
{
    Nurse::Nurse()
    {
    }

    Nurse::Nurse(std::string id)
    : Role(id)
    {
    }
    
    Nurse::Nurse(
        std::string id,
        std::string username,
        std::string password,
        std::string first_name,
        std::string last_name
    )
    : Role(id),
      username(username),
      password(password),
      first_name(first_name),
      last_name(last_name)
    {
    }
} // namespace pms