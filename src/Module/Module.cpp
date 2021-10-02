#include "Module.h"

#include <memory>
#include <string>
#include <iostream>

namespace pms
{
    Module::Module(std::shared_ptr<ResourcePool> resource_pool)
    : resource_pool_(resource_pool)
    {
    }

    const std::string Module::getOptionText() const
    {
        return module_option_text_;
    }
} // namespace pms