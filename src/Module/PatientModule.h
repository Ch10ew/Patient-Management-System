#ifndef PMS_PATIENTMODULE_H
#define PMS_PATIENTMODULE_H

#include "UI.h"
#include "../Structures/List.h"
#include "../Structures/Role.h"

#include <map>
#include <string>

namespace pms
{
    class NurseModule : protected UI
    {
        public:
            static void Init();
            static std::map<std::string, List<Role>> lists;


        private:
            
    };
} // namespace pms

#endif // PMS_PATIENTMODULE_H
