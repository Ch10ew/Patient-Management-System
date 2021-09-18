#include "DoctorModule.h"

#include "../Structures/List.h"
#include "../Structures/Patient.h"
#include "../Util/Util.h"

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
        bool exit = false;

        std::string* option_text = new std::string[4];
        option_text[0] = "View full patient list";
        option_text[1] = "Modify patient record";
        option_text[2] = "View patient list in descending order";
        option_text[3] = "Search for patient record";

        while (!exit)
        {
            int option = Util::Menu("Welcome, " + logged_in_doctor_->first_name, option_text, 4);

            // Run selected option
            switch (option)
            {
                case 0:
                    //PrintPatientList();
                    std::cout << "[DEBUG] Print Patient List" << std::endl;
                    break;
                case 1:
                    //Modify(Search());
                    std::cout << "[DEBUG] Search & Modify" << std::endl;
                    break;
                case 2:
                    //Pagination();
                    std::cout << "[DEBUG] Pagination for patient" << std::endl;
                    break;
                case 3:
                    //PrintPatient(Search());
                    std::cout << "[DEBUG] Search & View" << std::endl;
                    break;
                case 4:
                    logged_in_ = false;
                    exit = true;
                    break;
            }
        }

        // free pointer above
        delete[] option_text;
    }
} // namespace pms