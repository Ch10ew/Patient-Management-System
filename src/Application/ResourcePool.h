#ifndef PMS_RESOURCE_POOL_H
#define PMS_RESOURCE_POOL_H

#include "../Structures/List.h"
#include "../Structures/Nurse.h"
#include "../Structures/Doctor.h"
#include "../Structures/Patient.h"

#include <map>
#include <memory>

namespace pms
{
    class ResourcePool
    {
        public:
            // Constructor (Edit if necessary)
            // Used to load the data
            ResourcePool();
            
            // Stores all the data needed for the program
            List<std::shared_ptr<Nurse>> nurse_data;
            List<std::shared_ptr<Doctor>> doctor_data;
            List<std::shared_ptr<Patient>> patient_data;
            List<std::shared_ptr<Waiting>> waiting_data;
    };
} // namespace pms

#endif // PMS_RESOURCE_POOL_H