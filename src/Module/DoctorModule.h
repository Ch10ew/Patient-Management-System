#ifndef PMS_DOCTOR_MODULE_H
#define PMS_DOCTOR_MODULE_H

#include "UI.h"
#include "../Structures/List.h"
#include "../Structures/Role.h"

#include <memory>
#include <string>

namespace pms
{
    class DoctorModule : public UI
    {
        public:
            DoctorModule(std::shared_ptr<ResourcePool> resource_pool);
            void Run();
    };
} // namespace pms

#endif // PMS_DOCTOR_MODULE_H
