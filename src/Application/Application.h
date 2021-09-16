#ifndef PMS_APPLICATION_H
#define PMS_APPLICATION_H

#include "ResourcePool.h"
#include "../Structures/List.h"
#include "../Module/UI.h"

#include <memory>

namespace pms
{
    class Application
{
	public:
		// Constructor used to load the modules wanted & to call Run()
		Application();
	
	private:
		// Main program flow, contains a while loop checking
		// for `exit_`, otherwise, loads in the option text
		// and prompts for an option (then potentially pass
		// control over to one of the modules)
		void Run();
		
	private:
		std::shared_ptr<ResourcePool> resource_pool_ = std::make_shared<ResourcePool>();
		
		// This list holds all the modules to be used in the
		// system. Each module will be "loaded" in order and
		// will be displayed as options with the display text
		// tl;dr this is the "State Machine"
		pms::List<std::shared_ptr<UI>> modules_;
		
		// Flag for if the user wants to exit, used to keep the
		// program alive
		bool exit_ = false;;
};
} // namespace pms

#endif // PMS_APPLICATION_H
