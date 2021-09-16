#include "UI.h"

#include <memory>
#include <string>
#include <iostream>

namespace pms
{
    UI::UI(std::shared_ptr<ResourcePool> resource_pool)
    : resource_pool_(resource_pool)
    {
    }

    const std::string UI::getOptionText() const
    {
        return module_option_text_;
    }
} // namespace pms