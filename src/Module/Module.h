#ifndef PMS_MODULE_H
#define PMS_MODULE_H

#include "../Application/ResourcePool.h"

#include <memory>
#include <string>

namespace pms
{
    /**
     * @brief `Module` that serves as a target for Application to be used.
     * 
     * Expects to be given a `std::shared_ptr` of `ResourcePool`.
     * 
     * Meant to be inherited, and not to be used by its own.
     * 
     * Stores option text for use in `Application` (See `Application` class).
     * 
     * Contains a virtual `Run()` function to be overwritten. `Run()` should include code that handles
     * the "UI" component of a module as well, i.e. `Module` does not provide any code that controls
     * the program flow. In the expected program flow, `Application` will directly pass off control to
     * the `Module` that the user selects. Hence, any additional program flow (such as taking in inputs
     * to progress the program) will be entirely up to the child `Module`-inheriting classes (See
     * `Application` class).
     */
    class Module
    {
        public:
            
            Module(std::shared_ptr<ResourcePool> resource_pool);

            /**
             * @brief Virtual Destructor. Does nothing.
             */
            virtual ~Module() {}

            /**
             * @brief Virtual function to be overloaded by inheriting classes.
             * 
             * Used as the "driver code" for modules (See `Application` class).
             */
            virtual void Run() = 0;
            
            const std::string getOptionText() const;

        protected:
            /**
             * @brief Text for `Application` to display in its menu.
             */
            std::string module_option_text_;

            /**
             * @brief Pointer to `ResourcePool` instance.
             */
	    	std::shared_ptr<ResourcePool> resource_pool_;
    };
} // namespace pms

#endif // PMS_MODULE_H
