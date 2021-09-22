#include "NurseModule.h"

#include "../Util/Util.h"
#include "../Structures/List.h"
#include "../Structures/Patient.h"
#include "../Structures/CtimeWrapper.h"

#include <memory>
#include <iostream>
#include <cctype>
#include <cstring>
#include <sstream>
#include <iomanip>

namespace pms
{
    bool MatchAccount(std::shared_ptr<Nurse> n1, std::shared_ptr<Nurse> n2)
    {
        return (n1->username == n2->username) && (n1->password == n2->password);
    }

    NurseModule::NurseModule(std::shared_ptr<ResourcePool> resource_pool)
    : UI(resource_pool)
    {
        module_option_text_ = "Nurse Login";
    }

   
    void NurseModule::Run()
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

    void NurseModule::Login()
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
            std::cout << " = Nurse Login = " << std::endl;
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
            int found = resource_pool_->nurse_data.Search(std::make_shared<Nurse>("", username, password, "", ""), MatchAccount);
            if (found != -1)
            {
                logged_in_nurse_ = resource_pool_->nurse_data.At(found);
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

    void NurseModule::Menu()
    {
        bool exit = false;

        std::string* option_text = new std::string[7];
        option_text[0] = "Add a new patient";
        option_text[1] = "Modify patient record";
        option_text[2] = "View patient list in descending order";
        option_text[3] = "Call a patient";
        option_text[4] = "Search for patient record";
        option_text[5] = "Sort patient's list by waiting time";

        while (!exit)
        {
            int option = Util::Menu("Welcome, " + logged_in_nurse_->first_name, option_text, 6);

            // Run selected option
            std::cout << std::endl;
            std::cout << std::endl;
            switch (option)
            {
                case 0:
                    std::cout << " = Add a patient = " << std::endl;
                    std::cout << std::endl;
                    AddPatient();
                    break;
                case 1:
                    std::cout << " = Search & Modify = " << std::endl;
                    std::cout << std::endl;
                    //Modify(Search());
                    break;
                case 2:
                    std::cout << " = Print Patient List = " << std::endl;
                    std::cout << std::endl;
                    PrintPatientList();
                    break;
                case 3:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    //PrintPatient(Search());
                    break;
                case 4:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    //PrintPatient(Search());
                    break;
                case 5:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    //PrintPatient(Search());
                    break;
                case 6:
                    std::cout << "Logging out..." << std::endl;
                    logged_in_ = false;
                    logged_in_nurse_ = nullptr;
                    exit = true;
                    break;
            }
        }

        // free pointer above
        delete[] option_text;
    }

    void NurseModule::AddPatient()
    {
        std::string id;
        std::string first_name;
        std::string last_name;
        int age;
        char gender;
        std::string contact_number;
        std::string address;
        std::string disability;
        int priority;
        bool invalid_input = false;

        std::string* input_text = new std::string[7];
        input_text[0] = "First Name: ";
        input_text[1] = "Last Name: ";
        input_text[2] = "Age: ";
        input_text[3] = "Gender(F/M): ";
        input_text[4] = "Contact Number: ";
        input_text[5] = "Address: ";
        input_text[6] = "Disability: ";
        input_text[7] = "Priority Index";

        delete[] input_text;

        for(int i = 0; i < 8; i++){
            std::string tmp;
            std::string tmp2;
            std::string tmp3;
            if (invalid_input)
            {
                std::cout << "\n" << "========== Invalid " + input_text[i] + " ==========" << std::endl;
                invalid_input = false;
            }
                else
                    std::cout << "\n" << std::endl;
                    
            std::cout << input_text[i];
            switch (i)
            {
                case 0:
                    getline(std::cin, first_name);
                    break;
                case 1:
                    getline(std::cin, last_name);
                    break;
                case 2:
                    getline(std::cin, tmp);
                    try
                    {
                        age = std::stoi(tmp);
                    }
                    catch(const std::exception& e)
                    {
                        invalid_input = true;
                        i--;
                    }
                    break;
                case 3:
                    getline(std::cin, tmp2);
                    gender = toupper(tmp2[0]);
                    std::cout << tmp2 <<std::endl;
                    std::cout << gender << std::endl;
                    if(!(gender == 'F' || gender == 'M')){
                        invalid_input = true;
                        i--;
                    }
                    break;
                case 4:
                    getline(std::cin, contact_number);
                    break;
                case 5:
                    getline(std::cin, address);
                    break;
                case 6:
                    getline(std::cin, disability);
                    break;
                case 7:
                    getline(std::cin, tmp3);
                    try
                    {
                        priority = std::stoi(tmp);
                    }
                    catch(const std::exception& e)
                    {
                        invalid_input = true;
                        i--;
                    }
                    break;
            }
        }
        int size = resource_pool_->patient_data.Size();
        std::string id = Util::GenerateID("P", 8, size);
        resource_pool_->patient_data.InsertTail(std::make_shared<Patient>(
            id,
            first_name,
            last_name,
            age,
            gender,
            contact_number,
            address,
            disability,
            priority
        ));
        time_t time_temp = ctimew::Time();
        resource_pool_->waiting_data.InsertTail(std::make_shared<Waiting>(
            id,
            first_name,
            last_name,
            priority,
            time_temp
        ));
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "========== Patient Entered Successfully ==========" << std::endl;
        Patient copy = *(resource_pool_->patient_data.Tail());
        std::cout << copy.id << " - " << copy.first_name << " " << copy.last_name << std::endl;
        std::cout << "Age: " << copy.age << std::endl;
        std::cout << "Gender: " << copy.gender << std::endl;
        std::cout << "Contact Number: " << copy.contact_number << std::endl;
        std::cout << "Address: " << copy.address << std::endl;
        std::cout << "Disability: " << copy.disability << std::endl;
        std::cout << std::endl;
    }

    void NurseModule::PrintPatientList()
    {
        for (int i = 0; i < resource_pool_->patient_data.Size(); ++i)
        {
            Patient copy = *(resource_pool_->patient_data.At(i));
            
            std::cout << copy.id << " - " << copy.first_name << " " << copy.last_name << std::endl;
            std::cout << "Age: " << copy.age << std::endl;
            std::cout << "Gender: " << copy.gender << std::endl;
            std::cout << "Contact Number: " << copy.contact_number << std::endl;
            std::cout << "Address: " << copy.address << std::endl;
            std::cout << "Disability: " << copy.disability << std::endl;
            std::cout << "Visit History: " << std::endl;
            for (int j = 0; j < copy.visit_history.Size(); ++j)
            {
                std::cout << "\t" << "Visit #" << j + 1 << std::endl;
                std::cout << "\t" << "Sickness: " << copy.visit_history.At(j).sickness << std::endl;
                std::cout << "\t" << "Description: " << copy.visit_history.At(j).description << std::endl;
                std::cout << "\t" << "Visit Date: " << copy.visit_history.At(j).current_visit_date << std::endl;
                std::cout << "\t" << "Visit Time: " << copy.visit_history.At(j).current_visit_time << std::endl;
                std::cout << "\t" << "Doctor: " << copy.visit_history.At(j).doctor->id << " - " << copy.visit_history.At(j).doctor->first_name << copy.visit_history.At(j).doctor->last_name << std::endl;
                std::cout << "\t" << "Medicide Information: " << copy.visit_history.At(j).medicine_information << std::endl;
                
                if (j != copy.visit_history.Size() - 1)
                    std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    std::shared_ptr<Patient> NurseModule::Search()
    {
        int search_option;  // For normal search

        std::string* option_text = new std::string[8];
        option_text[0] = "Search by ID";
        option_text[1] = "Search by name";
        option_text[2] = "Search by age";
        option_text[3] = "Search by gender";
        option_text[4] = "Search by contact number";
        option_text[5] = "Search by address";
        option_text[6] = "Search by disability";
        option_text[7] = "Search by visit history";

        // Prompt for search criteria
        int option = Util::Menu("Search", option_text, 8);

        // Free pointer above
        delete[] option_text;

        // Run selected option
        if (option != 7)
        {
            // Prompt for search term
            std::cout << std::endl;
            std::cout << std::endl;
            std::string search_term;
            std::cout << "Search-term: ";
            getline(std::cin, search_term);

            // Print found instances
            List<int> indices;
            for (int pos = -1; pos < resource_pool_->patient_data.Size() - 1; )
            {
                // Print detail
                if (pos >= 0)
                    indices.InsertTail(pos);

                if (option == 0)  // ID
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>(search_term),
                        Util::MatchPatientID,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 1)  // Name
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", search_term, search_term, 0, 0, "", "", "", 0),
                        Util::MatchPatientName,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 2)  // Age
                {
                    // Convert input to int
                    int search_age;
                    try
                    {
                        search_age = std::stoi(search_term);
                    }
                    catch(...)
                    {
                        break;
                    }
                    
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", search_age, 0, "", "", "", 0),
                        Util::MatchPatientAge,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 3)  // Gender
                {
                    // Guard longer strings
                    if (search_term.length() > 1 || search_term.length() == 0)
                        break;
                    
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, search_term[0], "", "", "", 0),
                        Util::MatchPatientGender,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 4)  // Contact Number
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, search_term, "", "", 0),
                        Util::MatchPatientContactNumber,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 5)  // Address
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, "", search_term, "", 0),
                        Util::MatchPatientAddress,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 6)  // Disability
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, "", "", search_term, 0),
                        Util::MatchPatientDisability,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 8)  // Exit
                {
                    return nullptr;
                }
            }

            // Display the results & prompt for selection
            std::string* search_matches = new std::string[indices.Size()];
            for (int i = 0; i < indices.Size(); ++i)
            {
                std::string tmp;
                
                tmp += resource_pool_->patient_data.At(indices.At(i))->id;
                tmp += " - ";
                tmp += resource_pool_->patient_data.At(indices.At(i))->first_name;
                tmp += " ";
                tmp += resource_pool_->patient_data.At(indices.At(i))->last_name;

                search_matches[i] = tmp;
            }

            search_option = Util::Menu("Search Results", search_matches, indices.Size());

            // Free pointer above
            delete[] search_matches;
        }
        else  // Visit History
        {
            // Prompt more
            std::string* visit_option_text = new std::string[7];
            visit_option_text[0] = "Search by sickness";
            visit_option_text[1] = "Search by description";
            visit_option_text[2] = "Search by visit date";
            visit_option_text[3] = "Search by visit time";
            visit_option_text[4] = "Search by doctor id";
            visit_option_text[5] = "Search by doctor name";
            visit_option_text[6] = "Search by medicine information";

            int visit_option = Util::Menu("Search by Visit History", visit_option_text, 7);

            // Prompt for search term
            std::cout << std::endl;
            std::cout << std::endl;
            std::string search_term;
            std::cout << "Search-term: ";
            getline(std::cin, search_term);

            // Print found instances
            List<int> indices;
            for (int pos = -1; pos < resource_pool_->patient_data.Size() - 1; )
            {
                // Print detail
                if (pos >= 0)
                    indices.InsertTail(pos);

                // Loop through all visit history of current patient
                for (int pos2 = -1; pos2 < resource_pool_->patient_data.At(pos)->visit_history.Size() - 1; )
                {
                    if (option == 0)  // Sickness
                    {
                        // Update position
                        pos2 = resource_pool_->patient_data.Search(
                            std::make_shared<Patient>(search_term),
                            Util::MatchPatientID,
                            pos2
                        );
                    }
                    // send help i
                    // cri
                    // :")
                }
                if (pos == -1)
                    break;
            }
        }

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(search_option);
        }
        catch(...)
        {
            return nullptr;
        }
    }

    
} // namespace pms