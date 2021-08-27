#ifndef PMS_PATIENTMODULE_H
#define PMS_PATIENTMODULE_H

#include "../Database/Database.h"

#include <string>

namespace pms
{
    class PatientModule
    {
        public:
            // Patient GetPatient(int ID);
            // Patient GetPatient(std::string name);

        private:
            Database database_;
    };
} // namespace pms

#endif // PMS_PATIENTMODULE_H
