#ifndef PMS_APPLICATION_H
#define PMS_APPLICATION_H

#include "ResourcePool.h"
#include "../Structures/List.h"
#include "../Module/Module.h"

#include <memory>

namespace pms
{
	/**
     * @brief Main entry point of the program. Initializes a `ResourcePool` instance & loads `Module`s.
     * 
     * `pms::Application` initializes and keeps a "master copy" of the resources that will be used
     * throughout the system. All modules will be given a `std::shared_ptr` of `ResourcePool` to be used.
     * 
     * `pms::Application` holds a list of `Module`s, which is initialized (and can be added and removed)
     * in its constructor.
     */
    class Application
	{
		public:
			Application();
		
		private:
			void Run();
			
		private:
			/**
			 * @brief "Master" instance of `ResourcePool`. Contains all the data needed throughout
			 * the program.
			 */
			std::shared_ptr<ResourcePool> resource_pool_ = std::make_shared<ResourcePool>();
			
			/**
			 * @brief This list holds all the modules to be used in the system. Each module will be
			 * loaded in order, and will be displayed as options with the given option text.
			 * 
			 * In a normal program flow, this would be equivalent to a "state stack".
			 */
			pms::List<std::shared_ptr<Module>> modules_;
			
			/**
			 * @brief Flag for if the user wants to exit. Used to keep the program alive.
			 */
			bool exit_ = false;
	};
} // namespace pms

#endif // PMS_APPLICATION_H
