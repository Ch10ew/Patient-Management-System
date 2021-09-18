#ifndef PMS_UTIL_H
#define PMS_UTIL_H

#include "../Structures/List.h"

#include <iostream>
#include <limits>
#include <string>

namespace pms
{
    class Util
    {
        public:
            /**
             * @brief Menu template
             * 
             * @param options Option text to be displayed
             * @return int option selected (-1 means invalid)
             */
            static int Menu(std::string title, const std::string* options, const int size)
            {
                std::string input_string;
                bool invalid_input = false;
                int option = -1;
                bool exit = false;

                while (true)
                {
                    std::cout << std::endl;
                    std::cout << std::endl;

                    if (invalid_input)
                    {
                        std::cout << "\n" << "========== Invalid Input ==========" << std::endl;
                        invalid_input = false;
                    }
                    else
                        std::cout << "\n" << std::endl;
                    
                    // Display options
                    std::cout << " = " << title << " = " << std::endl;
                    std::cout << std::endl;
                    for (int i = 0; i < size; ++i)
                    {
                        std::cout << i + 1 << " - " << options[i] << std::endl;
                    }
                    std::cout << size + 1 << " - Exit" << std::endl;
                    std::cout << std::endl;
                    std::cout << "Enter an option: ";
                    std::cin >> input_string;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    try
                    {
                        option = std::stoi(input_string);
                        if (option > 0 && option <= size + 1)
                            invalid_input = false;
                        else
                            invalid_input = true;
                    }
                    catch (...)
                    {
                        invalid_input = true;
                    }

                    if (!invalid_input)
                    {
                        --option; // Make option like an index

                        if (option >= 0 && option <= size)
                        {
                            return option;
                        }
                    }
                }
            }
    };
} //namespace pms

#endif // PMS_UTIL_H