#ifndef PMS_UI_H
#define PMS_UI_H

#include "../Application/ResourcePool.h"

#include <memory>
#include <string>

namespace pms
{
    class UI
    {
        public:
            // Constructor (Edit if necessary)
            // Initialize that pointer in the protected section
            // for ResourcePool
            UI(std::shared_ptr<ResourcePool> resource_pool);

            // Destructor
            virtual ~UI() {}

            // Virtual function to be overloaded by inheriting
            // classes. Used as the "driver code" for each module
            // (See Application.h notes for reasons for this design
            // decision)
            virtual void Run() = 0;
            const std::string getOptionText() const;

        protected:
            // Text for Application class to display in its menu
            std::string module_option_text_;

            // Pointer to the resource pool to be used in the module
	    	std::shared_ptr<ResourcePool> resource_pool_;
    };
} // namespace pms

#endif // PMS_UI_H
