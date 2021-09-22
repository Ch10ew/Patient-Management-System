#ifndef PMS_UTIL_H
#define PMS_UTIL_H

#include "../Structures/List.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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
                    getline(std::cin, input_string);

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

            static std::string FitString(std::string input_string, const int width)
            {
                int count = 0;
                std::string return_string;

                if (input_string.length() > width - 3)
                {
                    for (int i = 0; i < width - 3; ++i)
                    {
                        return_string += input_string[i];
                    }
                    return_string += "...";
                }
                else
                {
                    return_string = input_string;
                    while (return_string.length() < width)
                    {
                        return_string += " ";
                    }
                }
                
                return return_string;
            }

            static bool MatchPatientID(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->id == p2->id;
            }

            static bool MatchPatientName(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                // use find
                return (p1->first_name == p2->first_name) || (p1->last_name == p2->last_name);
            }

            static bool MatchPatientAge(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->age == p2->age;
            }

            static bool MatchPatientGender(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->gender == p2->gender;
            }

            static bool MatchPatientContactNumber(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->contact_number == p2->contact_number;
            }

            static bool MatchPatientAddress(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                // use find
                return p1->address == p2->address;
            }

            static bool MatchPatientDisability(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->disability == p2->disability;
            }

            static bool MatchPatientVisit(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
            {
                return p1->disability == p2->disability;
            }

            static std::string GenerateID(std::string prefix, int length, int list_size)
            {
                std::stringstream ss;
                ss << prefix << std::setfill('0') << std::setw(length) << list_size;
                return ss.str();
            }

    };
} //namespace pms

#endif // PMS_UTIL_H