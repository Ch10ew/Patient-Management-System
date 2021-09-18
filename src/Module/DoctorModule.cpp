#include "DoctorModule.h"

#include "../Structures/List.h"
#include "../Structures/Patient.h"

#include <memory>
#include <iostream>

namespace pms
{
    bool MatchAccount(std::shared_ptr<Doctor> d1, std::shared_ptr<Doctor> d2)
    {
        return (d1->username == d2->username) && (d1->password == d2->password);
    }

    DoctorModule::DoctorModule(std::shared_ptr<ResourcePool> resource_pool)
    : UI(resource_pool)
    {
        module_option_text_ = "Doctor Login";
    }

    void DoctorModule::Run()
    {
        do
        {
            Login();
            if (logged_in_)
            {
                Menu();
            }
        }
        while (!exit_);
    }

    void DoctorModule::Login()
    {
        int option = -1;
        bool show_invalid = false;
        bool found = false;
        bool exit = false;
        std::string username, password;

        do
        {
            std::cout << std::endl;
            std::cout << std::endl;
            if (show_invalid)
            {
                std::cout << "\n" << "========== Invalid Credentials ==========" << std::endl;
                show_invalid = false;
            }
            else
                std::cout << "\n" << std::endl;
            
            // Display options
            std::cout << " = Login = " << std::endl;
            std::cout << std::endl;
            std::cout << "Username (\"!\" to exit): ";
            std::cin >> username;

            if (username == "!")
            {
                exit_ = true;
                return;
            }
            
            std::cout << "Password: ";
            std::cin >> password;

            // Run selected option
            int found = resource_pool_->doctor_data_.Search(std::make_shared<Doctor>("", username, password, "", "", ""), MatchAccount);
            if (found != -1)
            {
                logged_in_doctor_ = resource_pool_->doctor_data_.At(found);
                logged_in_ = true;
                exit = true;
            }
            else
            {
                show_invalid = true;
            }
        }
        while (!exit);
    }

    void DoctorModule::Menu()
    {
        int option = -1;
        bool exit = false;
        bool show_invalid = false;

        do
        {
            std::cout << std::endl;
            std::cout << std::endl;
            if (show_invalid)
            {
                std::cout << "\n" << "========== Invalid Input ==========" << std::endl;
                show_invalid = false;
            }
            else
                std::cout << "\n" << std::endl;
            
            // Display options
            std::cout << " = Welcome, " << logged_in_doctor_->first_name << " = " << std::endl;
            std::cout << "1 - View full patient list" << std::endl;
            std::cout << "2 - Modify patient record" << std::endl;
            std::cout << "3 - View patient list in descending order" << std::endl;
            std::cout << "4 - Search for patient record" << std::endl;
            std::cout << "5 - Logout" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter an option: ";
            std::cin >> option;

            switch (option)
            {
                case 1:
                    //PrintPatientList();
                    std::cout << "[DEBUG] Print Patient List" << std::endl;
                    break;
                case 2:
                    //Modify(Search());
                    std::cout << "[DEBUG] Search & Modify" << std::endl;
                    break;
                case 3:
                    //Pagination();
                    std::cout << "[DEBUG] Pagination for patient" << std::endl;
                    break;
                case 4:
                    //PrintPatient(Search());
                    std::cout << "[DEBUG] Search & View" << std::endl;
                    break;
                case 5:
                    logged_in_ = false;
                    exit = true;
                    break;
                default:
                    show_invalid = true;
                    break;
            }
        }
        while (!exit);
            
    }
} // namespace pms