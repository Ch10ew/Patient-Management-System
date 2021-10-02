#ifndef PMS_RESOURCE_POOL_H
#define PMS_RESOURCE_POOL_H

#include "../Structures/List.h"
#include "../Structures/Nurse.h"
#include "../Structures/Doctor.h"
#include "../Structures/Patient.h"

#include <memory>

namespace pms
{
    /**
     * @brief Container for data used throughout the system. Currently stores: `nurse_data`,
     * `doctor_data`, `patient_data`, `waiting_data`.
     */
    class ResourcePool
    {
        public:
            /**
             * @brief Loads the default data... Because... No database...
             */
            ResourcePool();
            
            /**
             * @brief Container for all registered nurses.
             */
            List<std::shared_ptr<Nurse>> nurse_data;
            
            /**
             * @brief Container for all registered doctors.
             */
            List<std::shared_ptr<Doctor>> doctor_data;

            /**
             * @brief Container for all registered patients.
             */
            List<std::shared_ptr<Patient>> patient_data;

            /**
             * @brief The active waiting list of the clinic.
             */
            List<std::shared_ptr<Waiting>> waiting_data;
    };
} // namespace pms

#endif // PMS_RESOURCE_POOL_H