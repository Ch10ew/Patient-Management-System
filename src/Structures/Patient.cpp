#include "Patient.h"

#include <string>

namespace pms
{
    Patient::Patient()
    {
    }

    Patient::Patient(std::string id)
    : Role(id)
    {
    }
    Patient::Patient(
        std::string id,
        std::string first_name,
        std::string last_name,
        int age,
        char gender,
        std::string contact_number,
        std::string address
    )
    : Role(id),
      first_name(first_name),
      last_name(last_name),
      age(age),
      gender(gender),
      contact_number(contact_number),
      address(address)
    {
    }

} // namespace pms