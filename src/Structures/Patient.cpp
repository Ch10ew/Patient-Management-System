#include "Patient.h"

#include <string>

namespace pms
{
    /**
     * @brief Default constructor. Does nothing.
     */
    Visit::Visit()
    {
    }

    /**
     * @brief Construct a new Visit::Visit object.
     * 
     * @param sickness 
     * @param description 
     * @param registration_time 
     * @param doctor 
     * @param medicine_information 
     */
    Visit::Visit(
        std::string sickness,
        std::string description,
        time_t registration_time,
        std::shared_ptr<Doctor> doctor,
        std::string medicine_information
    )
    : sickness(sickness),
      description(description),
      registration_time(registration_time),
      doctor(doctor),
      medicine_information(medicine_information)
    {
    }

    /**
     * @brief Default constructor. Does nothing.
     */
    VisitButForPrinting::VisitButForPrinting()
    {
    }

    /**
     * @brief Construct a new VisitButForPrinting::VisitButForPrinting object.
     * 
     * @param patient_id 
     * @param sickness 
     * @param description 
     * @param registration_time 
     * @param doctor 
     * @param medicine_information 
     */
    VisitButForPrinting::VisitButForPrinting(
        std::string patient_id,
        std::string sickness,
        std::string description,
        time_t registration_time,
        std::shared_ptr<Doctor> doctor,
        std::string medicine_information
    )
    : patient_id(patient_id),
      sickness(sickness),
      description(description),
      registration_time(registration_time),
      doctor(doctor),
      medicine_information(medicine_information)
    {
    }

    /**
     * @brief Default constructor. Does nothing.
     */
    Waiting::Waiting()
    {
    }

    /**
     * @brief Construct a new Waiting::Waiting object
     * 
     * @param id 
     * @param first_name 
     * @param last_name 
     * @param priority 
     * @param registration_time 
     */
    Waiting::Waiting(
      std::string id,
      std::string first_name,
      std::string last_name,
      int priority,
      time_t registration_time
    )
    : id(id),
    first_name(first_name),
    last_name(last_name),
    priority(priority),
    registration_time(registration_time)
    {
    }

    /**
     * @brief Default constructor. Does nothing.
     */
    Patient::Patient()
    {
    }

    /**
     * @brief Construct a new Patient::Patient object
     * 
     * @param id 
     */
    Patient::Patient(std::string id)
    : Role(id)
    {
    }
    
    /**
     * @brief Construct a new Patient::Patient object
     * 
     * @param id 
     * @param first_name 
     * @param last_name 
     * @param age 
     * @param gender 
     * @param contact_number 
     * @param address 
     * @param disability 
     * @param priority 
     */
    Patient::Patient(
        std::string id,
        std::string first_name,
        std::string last_name,
        int age,
        char gender,
        std::string contact_number,
        std::string address,
        std::string disability,
        int priority
    )
    : Role(id),
      first_name(first_name),
      last_name(last_name),
      age(age),
      gender(gender),
      contact_number(contact_number),
      address(address),
      disability(disability),
      priority(priority)
    {
    }

} // namespace pms