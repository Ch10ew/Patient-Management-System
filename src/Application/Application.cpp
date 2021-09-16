#include "Application.h"

#include "../Structures/List.h"
#include "../Module/NurseModule.h"
#include "../Module/DoctorModule.h"

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
        int option = -1;
        bool show_invalid = false;

        do
        {
            if (show_invalid)
            {
                std::cout << "\n" << "========== Invalid Input ==========" << std::endl;
                show_invalid = false;
            }
            else
                std::cout << "\n" << std::endl;
            
            // Display options
            std::cout << " = Patient Management System = " << std::endl;
            std::cout << std::endl;
            for (int i = 0; i < modules_.Size(); ++i)
            {
                std::cout << i + 1 << " - " << modules_.At(i)->getOptionText() << std::endl;
            }
            std::cout << modules_.Size() + 1 << " - Exit" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter an option: ";
            std::cin >> option;

            --option;  // Make the option be like an index

            // Run selected option
            if (option >= 0 && option <= modules_.Size())
            {
                if (option == modules_.Size())
                    exit_ = true;
                else
                    modules_.At(option)->Run();
            }
            else
                show_invalid = true;
        }
        while (!exit_);
    }
	
} // namespace pms