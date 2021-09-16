#include "Doctor.h"

#include <string>

namespace pms
{
    Doctor::Doctor()
    {
    }

    Doctor::Doctor(std::string id)
    : Role(id)
    {
    }
    
    Doctor::Doctor(
        std::string id,
        std::string username,
        std::string password,
        std::string first_name,
        std::string last_name,
        std::string specialism
    )
    : Role(id),
      username(username),
      password(password),
      first_name(first_name),
      last_name(last_name),
      specialism(specialism)
    {
    }
} // namespace pms