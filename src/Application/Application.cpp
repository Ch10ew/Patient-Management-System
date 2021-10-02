#include "Application.h"

#include "../Structures/List.h"
#include "../Module/NurseModule.h"
#include "../Module/DoctorModule.h"
#include "../Util/Util.h"

#include <iostream>
#include <string>
#include <memory>

namespace pms
{
    /**
     * @brief Adds modules into the module list and calls Run().
     */
    Application::Application()
    {
        modules_.InsertTail(std::make_shared<NurseModule>(resource_pool_));
        modules_.InsertTail(std::make_shared<DoctorModule>(resource_pool_));

        Run();
    }
	
    /**
     * @brief Runs the menu for selecting a module to enter.
     * 
     * Gets the option text of each module, creates a menu with the option text (with an
     * additional "Exit" option). Then prompts and directs the user to their selected module's
     * `Module::Run()` function.
     * 
     * Keeps the program alive until "Exit" is selected.
     */
	void Application::Run()
    {
        // Create C array of strings from each module's option text
        std::string* option_text = new std::string[modules_.Size()];
        for (int i = 0; i < modules_.Size(); ++i)
        {
            option_text[i] = modules_.At(i)->getOptionText();
        }

        while (!exit_)
        {
            int option = util::Menu("Patient Management System", option_text, modules_.Size());

            // Run selected option
            if (option == modules_.Size())
            {
                exit_ = true;
            }
            else
            {
                modules_.At(option)->Run();
            }
        }

        // free pointer above
        delete[] option_text;
    }
	
} // namespace pms