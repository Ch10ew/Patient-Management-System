#ifndef PMS_NURSE_MODULE_H
#define PMS_NURSE_MODULE_H

#include "UI.h"
#include "../Structures/List.h"
#include "../Structures/Role.h"

#include <memory>
#include <string>

namespace pms
{
    class NurseModule : public UI
    {
        public:
            NurseModule(std::shared_ptr<ResourcePool> resource_pool);
            void Run();
    };
} // namespace pms

#endif // PMS_NURSE_MODULE_H
