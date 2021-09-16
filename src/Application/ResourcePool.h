#ifndef PMS_RESOURCE_POOL_H
#define PMS_RESOURCE_POOL_H

#include "../Structures/List.h"
#include "../Structures/Role.h"

#include <map>

namespace pms
{
    class ResourcePool
    {
        public:
            // Constructor (Edit if necessary)
            // Used to load the data
            ResourcePool();
            
            // Used to get a copy of the specified list
            pms::List<Role> GetData(std::string key);
        
        private:
            // [POTENTIAL CHANGE]
            // Stores all the data needed for the program
            // Expected structure:
            // key, value
            // 'Patient', [patient list]
            // 'Doctor', [doctor list]
            std::map<std::string, pms::List<Role>> lists;
    };
} // namespace pms

#endif // PMS_RESOURCE_POOL_H