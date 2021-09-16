#include "DoctorModule.h"

#include <memory>
#include <iostream>

namespace pms
{
    DoctorModule::DoctorModule(std::shared_ptr<ResourcePool> resource_pool)
    : UI(resource_pool)
    {
        module_option_text_ = "Doctor Login";
    }

    void DoctorModule::Run()
    {
        std::cout << std::endl;
        std::cout << "This is the doctor module." << std::endl;
        std::cout << "Returning to menu..." << std::endl;
    }
} // namespace pms