#ifndef PMS_UTIL_H
#define PMS_UTIL_H

#include "../Structures/List.h"
#include "../Structures/CtimeWrapper.h"
#include "Console.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

namespace pms
{
    namespace util
    {
        static void ClearScreen()
        {
            static bool init_done = false;
            /*std::cout << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;*/
            if (!init_done)
                console::InitConsole();
            
            std::cout << console::AnsiEsc(console::ANSI_SEQ::ESC_CLEAR_SCREEN);
        }

        /**
         * @brief Menu template
         * 
         * @param options Option text to be displayed
         * @return int option selected (-1 means invalid)
         */
        static int Menu(std::string title, const std::string* options, const int size, bool clear_screen = true)
        {
            std::string input_string;
            bool invalid_input = false;
            int option = -1;

            while (true)
            {
                if (clear_screen)
                    ClearScreen();

                if (invalid_input)
                {
                    std::cout << "========== Invalid Input ==========" << std::endl;
                    invalid_input = false;
                }
                else
                    std::cout << std::endl;
                
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

        static std::string ToLower(std::string input_string)
        {
            std::string ret;
            for (char c : input_string)
            {
                ret += tolower(c);
            }

            return ret;
        }

        static std::string FitString(std::string input_string, const int width)
        {
            int count = 0;
            std::string return_string;

            if (input_string.length() == width)
            {
                return input_string;
            }
            else if (input_string.length() < width)
            {
                return_string = input_string;
                while (return_string.length() < width)
                {
                    return_string += " ";
                }

            }
            else if (input_string.length() > width - 3)
            {
                for (int i = 0; i < width - 3; ++i)
                {
                    return_string += input_string[i];
                }
                return_string += "...";
            }
            
            return return_string;
        }

        static bool MatchPatientId(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            int res = ToLower(p1->id).find(ToLower(p2->id));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchPatientName(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            int res1 = ToLower(p1->first_name).find(ToLower(p2->first_name));
            int res2 = ToLower(p1->last_name).find(ToLower(p2->last_name));
            if (res1 != std::string::npos || res2 != std::string::npos)
                return true;
            return false;
        }

        static bool MatchPatientAge(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            return p1->age == p2->age;
        }

        static bool MatchPatientGender(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            return tolower(p1->gender) == tolower(p2->gender);
        }

        static bool MatchPatientContactNumber(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            int res = ToLower(p1->contact_number).find(ToLower(p2->contact_number));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchPatientAddress(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            int res = ToLower(p1->address).find(ToLower(p2->address));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchPatientDisability(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
        {
            int res = ToLower(p1->disability).find(ToLower(p2->disability));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchVisitSickness(const Visit& v1, const Visit& v2)
        {
            int res = ToLower(v1.sickness).find(ToLower(v2.sickness));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchVisitDescription(const Visit& v1, const Visit& v2)
        {
            int res = ToLower(v1.description).find(ToLower(v2.description));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchVisitVisitDate(const Visit& v1, const Visit& v2)
        {
            struct tm t1 = *ctimew::StructTM(v1.registration_time);
            struct tm t2 = *ctimew::StructTM(v2.registration_time);

            return (t1.tm_year == t2.tm_year) ||
                (t1.tm_mon == t2.tm_mon) ||
                (t1.tm_mday == t2.tm_mday) ||
                (t1.tm_hour == t2.tm_hour) ||
                (t1.tm_min == t2.tm_min) ||
                (t1.tm_sec == t2.tm_sec);
        }

        static bool MatchVisitDoctorId(const Visit& v1, const Visit& v2)
        {
            int res = ToLower(v1.doctor->id).find(ToLower(v2.doctor->id));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool MatchVisitDoctorName(const Visit& v1, const Visit& v2)
        {
            int res1 = ToLower(v1.doctor->first_name).find(ToLower(v2.doctor->first_name));
            int res2 = ToLower(v1.doctor->last_name).find(ToLower(v2.doctor->last_name));
            if (res1 != std::string::npos || res2 != std::string::npos)
                return true;
            return false;
        }

        static bool MatchVisitMedicineInformation(const Visit& v1, const Visit& v2)
        {
            int res = ToLower(v1.medicine_information).find(ToLower(v2.medicine_information));
            if (res != std::string::npos)
                return true;
            return false;
        }

        static bool ComparePatientIdAsc(const Patient& p1, const Patient& p2)
        {
            std::string pid1_str = p1.id.substr(1);
            std::string pid2_str = p2.id.substr(1);
            int pid1 = std::stoi(pid1_str);
            int pid2 = std::stoi(pid2_str);
            return pid1 < pid2;
        }

        static bool ComparePatientIdDesc(const Patient& p1, const Patient& p2)
        {
            std::string pid1_str = p1.id.substr(1);
            std::string pid2_str = p2.id.substr(1);
            int pid1 = std::stoi(pid1_str);
            int pid2 = std::stoi(pid2_str);
            return pid1 > pid2;
        }

        static bool ComparePatientFirstNameAsc(const Patient& p1, const Patient& p2)
        {
            return p1.first_name < p2.first_name;
        }

        static bool ComparePatientFirstNameDesc(const Patient& p1, const Patient& p2)
        {
            return p1.first_name > p2.first_name;
        }

        static bool ComparePatientLastNameAsc(const Patient& p1, const Patient& p2)
        {
            return p1.last_name < p2.last_name;
        }

        static bool ComparePatientLastNameDesc(const Patient& p1, const Patient& p2)
        {
            return p1.last_name > p2.last_name;
        }

        static bool ComparePatientAgeAsc(const Patient& p1, const Patient& p2)
        {
            return p1.age < p2.age;
        }

        static bool ComparePatientAgeDesc(const Patient& p1, const Patient& p2)
        {
            return p1.age > p2.age;
        }

        static bool ComparePatientGenderAsc(const Patient& p1, const Patient& p2)
        {
            return p1.gender < p2.gender;
        }

        static bool ComparePatientGenderDesc(const Patient& p1, const Patient& p2)
        {
            return p1.gender > p2.gender;
        }

        static bool ComparePatientContactNumberAsc(const Patient& p1, const Patient& p2)
        {
            return p1.contact_number < p2.contact_number;
        }

        static bool ComparePatientContactNumberDesc(const Patient& p1, const Patient& p2)
        {
            return p1.contact_number > p2.contact_number;
        }

        static bool ComparePatientAddressAsc(const Patient& p1, const Patient& p2)
        {
            return p1.address < p2.address;
        }

        static bool ComparePatientAddressDesc(const Patient& p1, const Patient& p2)
        {
            return p1.address > p2.address;
        }

        static bool ComparePatientDisabilityAsc(const Patient& p1, const Patient& p2)
        {
            return p1.disability < p2.disability;
        }

        static bool ComparePatientDisabilityDesc(const Patient& p1, const Patient& p2)
        {
            return p1.disability > p2.disability;
        }

        static bool ComparePatientVisitsAsc(const Patient& p1, const Patient& p2)
        {
            return p1.visit_history.Size() < p2.visit_history.Size();
        }

        static bool ComparePatientVisitsDesc(const Patient& p1, const Patient& p2)
        {
            return p1.visit_history.Size() > p2.visit_history.Size();
        }

        static std::string GenerateId(std::string prefix, int length, int list_size)
        {
            std::stringstream ss;
            ss << prefix << std::setfill('0') << std::setw(length) << list_size;
            return ss.str();
        }
    } //namespace util
} //namespace pms

#endif // PMS_UTIL_H