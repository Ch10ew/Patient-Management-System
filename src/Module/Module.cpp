#include "Module.h"

#include <memory>
#include <string>

namespace pms
{
    /**
     * @brief Initializes the stored `ResourcePool` `std::shared_ptr`.
     * 
     * @param resource_pool Pointer to instance of `ResourcePool`. Expected to be given by `Application`.
     */
    Module::Module(std::shared_ptr<ResourcePool> resource_pool)
    : resource_pool_(resource_pool)
    {
    }

    /**
     * @brief Get the Option Text object
     * @return const std::string 
     */
    const std::string Module::getOptionText() const
    {
        return module_option_text_;
    }
} // namespace pms