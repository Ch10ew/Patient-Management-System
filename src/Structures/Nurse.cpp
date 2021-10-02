#include "Nurse.h"

#include <string>

namespace pms
{
    /**
     * @brief Default constructor. Does nothing.
     */
    Nurse::Nurse()
    {
    }

    /**
     * @brief Construct a new Nurse::Nurse object
     * 
     * @param id 
     */
    Nurse::Nurse(std::string id)
    : Role(id)
    {
    }
    
    /**
     * @brief Construct a new Nurse::Nurse object
     * 
     * @param id 
     * @param username 
     * @param password 
     * @param first_name 
     * @param last_name 
     */
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