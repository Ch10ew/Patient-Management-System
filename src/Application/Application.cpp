#include "Application.h"

#include "../Structures/List.h"
#include "../Module/Module.h"
#include "../Module/NurseModule.h"
#include "../Module/DoctorModule.h"
#include "../Util/Util.h"

#include <iostream>
#include <string>
#include <limits>
#include <memory>

namespace pms
{
    Application::Application()
    {
        modules_.InsertTail(std::make_shared<NurseModule>(resource_pool_));
        modules_.InsertTail(std::make_shared<DoctorModule>(resource_pool_));

        Run();
    }
	
	void Application::Run()
    {
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