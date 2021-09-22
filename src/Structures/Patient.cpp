#include "Patient.h"

#include <string>

namespace pms
{
    Visit::Visit()
    {
    }

    Visit::Visit(
        std::string sickness,
        std::string description,
        std::string current_visit_date,
        std::string current_visit_time,
        std::shared_ptr<Doctor> doctor,
        std::string medicine_information
    )
    : sickness(sickness),
      description(description),
      current_visit_date(current_visit_date),
      current_visit_time(current_visit_time),
      doctor(doctor),
      medicine_information(medicine_information)
    {
    }

    VisitButForPrinting::VisitButForPrinting()
    {
    }

    VisitButForPrinting::VisitButForPrinting(
        std::string id,
        std::string sickness,
        std::string description,
        std::string current_visit_date,
        std::string current_visit_time,
        std::shared_ptr<Doctor> doctor,
        std::string medicine_information
    )
    : id(id),
      sickness(sickness),
      description(description),
      current_visit_date(current_visit_date),
      current_visit_time(current_visit_time),
      doctor(doctor),
      medicine_information(medicine_information)
    {
    }

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
        std::string address,
        std::string disability
    )
    : Role(id),
      first_name(first_name),
      last_name(last_name),
      age(age),
      gender(gender),
      contact_number(contact_number),
      address(address),
      disability(disability)
    {
    }

} // namespace pms