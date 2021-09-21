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

    bool MatchPatientID(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->id == p2->id;
    }

    bool MatchPatientName(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        // use find
        return (p1->first_name == p2->first_name) || (p1->last_name == p2->last_name);
    }

    bool MatchPatientAge(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->age == p2->age;
    }

    bool MatchPatientGender(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->gender == p2->gender;
    }

    bool MatchPatientContactNumber(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->contact_number == p2->contact_number;
    }

    bool MatchPatientAddress(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        // use find
        return p1->address == p2->address;
    }

    bool MatchPatientDisability(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->disability == p2->disability;
    }

    bool MatchPatientVisit(std::shared_ptr<Patient> p1, std::shared_ptr<Patient> p2)
    {
        return p1->disability == p2->disability;
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
            std::cout << " = Doctor Login = " << std::endl;
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
            int found = resource_pool_->doctor_data.Search(std::make_shared<Doctor>("", username, password, "", "", ""), MatchAccount);
            if (found != -1)
            {
                logged_in_doctor_ = resource_pool_->doctor_data.At(found);
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
            std::cout << std::endl;
            std::cout << std::endl;
            switch (option)
            {
                case 0:
                    std::cout << " = Print Patient List = " << std::endl;
                    std::cout << std::endl;
                    PrintPatientList();
                    break;
                case 1:
                    std::cout << " = Search & Modify = " << std::endl;
                    std::cout << std::endl;
                    //Modify(Search());
                    break;
                case 2:
                    std::cout << " = Pagination for patient = " << std::endl;
                    std::cout << std::endl;
                    //Pagination();
                    break;
                case 3:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    //PrintPatient(Search());
                    break;
                case 4:
                    std::cout << "Logging out..." << std::endl;
                    logged_in_ = false;
                    logged_in_doctor_ = nullptr;
                    exit = true;
                    break;
            }
        }

        // free pointer above
        delete[] option_text;
    }

    void DoctorModule::PrintPatientList()
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

    std::shared_ptr<Patient> DoctorModule::Search()
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
                        MatchPatientID,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 1)  // Name
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", search_term, search_term, 0, 0, "", "", ""),
                        MatchPatientName,
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
                        std::make_shared<Patient>("", "", "", search_age, 0, "", "", ""),
                        MatchPatientAge,
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
                        std::make_shared<Patient>("", "", "", 0, search_term[0], "", "", ""),
                        MatchPatientGender,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 4)  // Contact Number
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, search_term, "", ""),
                        MatchPatientContactNumber,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 5)  // Address
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, "", search_term, ""),
                        MatchPatientAddress,
                        pos
                    );
                    if (pos == -1)
                        break;
                }
                if (option == 6)  // Disability
                {
                    // Update position
                    pos = resource_pool_->patient_data.Search(
                        std::make_shared<Patient>("", "", "", 0, 0, "", "", search_term),
                        MatchPatientDisability,
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
                            MatchPatientID,
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

    void DoctorModule::Pagination()
    {
        const int WIDTH = 104;
        const int HEIGHT = 30;

        std::cout << "                              ------------------------------------------" << std::endl;
        std::cout << "                                                Patients" << std::endl;
        std::cout << "                              ------------------------------------------" << std::endl;
        std::cout << "";

    }
} // namespace pms