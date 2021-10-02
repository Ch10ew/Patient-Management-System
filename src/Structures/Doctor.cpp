#include "Doctor.h"

#include <string>

namespace pms
{
    /**
     * @brief Default constructor. Does nothing.
     * 
     */
    Doctor::Doctor()
    {
    }

    /**
     * @brief Construct a new Doctor::Doctor object
     * 
     * @param id 
     */
    Doctor::Doctor(std::string id)
    : Role(id)
    {
    }
    
    /**
     * @brief Construct a new Doctor::Doctor object
     * 
     * @param id 
     * @param username 
     * @param password 
     * @param first_name 
     * @param last_name 
     * @param specialism 
     */
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