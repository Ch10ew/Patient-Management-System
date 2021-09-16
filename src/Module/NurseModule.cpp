#include "NurseModule.h"

#include <memory>
#include <iostream>

namespace pms
{
    NurseModule::NurseModule(std::shared_ptr<ResourcePool> resource_pool)
    : UI(resource_pool)
    {
        module_option_text_ = "Nurse Login";
    }

    void NurseModule::Run()
    {
        std::cout << std::endl;
        std::cout << "This is the nurse module." << std::endl;
        std::cout << "Returning to menu..." << std::endl;
    }
} // namespace pms