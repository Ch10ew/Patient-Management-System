#include "DoctorModule.h"

#include "../Structures/List.h"
#include "../Structures/Patient.h"
#include "../Util/Util.h"
#include "../Structures/CtimeWrapper.h"

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
            std::cout << " = Doctor Login = " << std::endl;
            std::cout << std::endl;
            std::cout << "Username (\"!\" to exit): ";
            std::cin >> username;
            std::cin.ignore();

            if (username == "!")
            {
                exit_ = true;
                return;
            }
            
            std::cout << "Password: ";
            std::cin >> password;
            std::cin.ignore();

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
            int option = util::Menu("Welcome, " + logged_in_doctor_->first_name, option_text, 4);

            // DEBUG ======
            std::shared_ptr<Patient> res;
            // DEBUG ======

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
                    //std::cout << " = Search & Modify = " << std::endl;
                    //std::cout << std::endl;
                    res = Search();
                    if (res)
                        std::cout << res->id << std::endl;
                    std::cout << "done" << std::endl;
                    //Modify(Search());
                    break;
                case 2:
                    std::cout << " = Pagination for patient = " << std::endl;
                    std::cout << std::endl;
                    Pagination();
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
                std::cout << "\t" << "Visit Time: " << ctimew::FormatTime(ctimew::StructTM(copy.visit_history.At(j).registration_time)) << std::endl;
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
        int option = util::Menu("Search", option_text, 8);

        // Free pointer above
        delete[] option_text;
        
        // Run based on option selected
        std::string search_term;
        switch (option)
        {
            case 0:  // ID
                search_term = PromptSearch("ID");
                //return SearchByID(search_term);
                return SearchBy(Patient(search_term), util::MatchPatientID);
                break;
            case 1:  // Name
                search_term = PromptSearch("name");
                return SearchBy(Patient("", search_term, search_term, 0, 0, "", "", "", 0), util::MatchPatientName);
                break;
            case 2:  // Age
                search_term = PromptSearch("age");
                int search_age;
                try
                {
                    search_age = std::stoi(search_term);
                }
                catch(...)
                {
                    std::cout << " - No results found - " << std::endl;
                    return nullptr;
                }
                return SearchBy(Patient("", "", "", search_age, 0, "", "", "", 0), util::MatchPatientAge);
                break;
            case 3:  // Gender
                search_term = PromptSearch("gender");
                return SearchBy(Patient("", "", "", 0, search_term[0], "", "", "", 0), util::MatchPatientGender);
                break;
            case 4:  // Contact Number
                search_term = PromptSearch("contact number");
                return SearchBy(Patient("", "", "", 0, 0, search_term, "", "", 0), util::MatchPatientContactNumber);
                break;
            case 5:  // Address
                search_term = PromptSearch("address");
                return SearchBy(Patient("", "", "", 0, 0, "", search_term, "", 0), util::MatchPatientAddress);
                break;
            case 6:  // Disability
                search_term = PromptSearch("disability");
                return SearchBy(Patient("", "", "", 0, 0, "", "", search_term, 0), util::MatchPatientDisability);
                break;
            case 7:  // Visit History
                return SearchByVisitHistory();
                break;
            case 8:  // Exit
                return nullptr;
                break;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByVisitHistory()
    {
        std::string* option_text = new std::string[6];
        option_text[0] = "Search by sickness";
        option_text[1] = "Search by description";
        option_text[2] = "Search by visit date";
        option_text[3] = "Search by doctor id";
        option_text[4] = "Search by doctor name";
        option_text[5] = "Search by medicine information";

        // Prompt for search criteria
        int option = util::Menu("Search", option_text, 6);

        // Free pointer above
        delete[] option_text;
        
        // Run based on option selected
        std::string search_term;
        switch (option)
        {
            case 0:  // Sickness
                search_term = PromptSearch("sickness");
                return SearchBy(Visit(search_term, "", 0, nullptr, ""), util::MatchVisitSickness);
                break;
            case 1:  // Description
                search_term = PromptSearch("description");
                return SearchBy(Visit("", search_term, 0, nullptr, ""), util::MatchVisitDescription);
                break;
            case 2:  // Visit Date
                search_term = PromptSearch("visit date");
                time_t search_time;
                try
                {
                    search_time = ctimew::GetTimeTFromString(search_term);
                }
                catch(...)
                {
                    std::cout << " - No results found - " << std::endl;
                    return nullptr;
                }
                return SearchBy(Visit("", "", search_time, nullptr, ""), util::MatchVisitVisitDate);
                break;
            case 3:  // Doctor ID
                search_term = PromptSearch("doctor id");
                return SearchBy(
                    Visit("", "", 0, std::make_shared<Doctor>(search_term), ""),
                    util::MatchVisitDoctorID
                );
                break;
            case 4:  // Doctor Name
                search_term = PromptSearch("doctor name");
                return SearchBy(
                    Visit("", "", 0, std::make_shared<Doctor>("", "", "", search_term, search_term, ""), ""),
                    util::MatchVisitDoctorName
                );
                break;
            case 5:  // Medicine Information
                search_term = PromptSearch("medicine information");
                return SearchBy(
                    Visit("", "", 0, nullptr, search_term),
                    util::MatchVisitMedicineInformation
                );
                break;
            case 6:  // Exit
                return nullptr;
                break;
        }
    }

    std::string DoctorModule::PromptSearch(std::string attribute)
    {
        std::string input_string;

        // Display options
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << " = Search by " << attribute << " = " << std::endl;
        std::cout << std::endl;
        if (attribute == "visit date")
        {
            std::cout << "Date format is YYYY/MM/DD HH:MM:SS. Loosely searches for any date/time field that matches." << std::endl;
            std::cout << "Search Term: ";
        }
        else
        {
            std::cout << "Search Term: ";
        }
        getline(std::cin, input_string);

        return input_string;
    }

    void DoctorModule::Pagination()
    {
        bool invalid_input = false;
        bool exit = false;

        const int WIDTH = 104;
        const int HEIGHT = 30;
        int lines = HEIGHT - 8; // for header & footer
        int page_count = (int)ceil((double)resource_pool_->patient_data.Size() / (double)lines);
        int current_page_index = 0;
        std::string input;

        while (!exit)
        {
            lines = HEIGHT - 8; // reset lines


            // "Header" text
            std::cout << "                              ------------------------------------------" << std::endl;
            std::cout << "                                                Patients" << std::endl;
            std::cout << "                              ------------------------------------------" << std::endl;
            std::cout << "ID      First Name  Last Name   Age Gender  Contact         Address                 Disability  Visits" << std::endl;

            // Create sorted list
            List<pms::Patient> copy;
            for (int i = 0; i < resource_pool_->patient_data.Size(); ++i)
            {
                Patient p_tmp = *resource_pool_->patient_data.At(i);

                /*Patient p_tmp;
                p_tmp.id = resource_pool_->patient_data.At(i)->id;
                p_tmp.first_name = resource_pool_->patient_data.At(i)->first_name;
                p_tmp.last_name = resource_pool_->patient_data.At(i)->last_name;
                p_tmp.age = resource_pool_->patient_data.At(i)->age;
                p_tmp.gender = resource_pool_->patient_data.At(i)->gender;
                p_tmp.contact_number = resource_pool_->patient_data.At(i)->contact_number;
                p_tmp.address = resource_pool_->patient_data.At(i)->address;
                p_tmp.disability = resource_pool_->patient_data.At(i)->disability;
                p_tmp.priority = resource_pool_->patient_data.At(i)->priority;
                
                for (int j = 0; j < resource_pool_->patient_data.At(i)->visit_history.Size(); ++j)
                {
                    Visit v_tmp;
                    v_tmp.sickness = resource_pool_->patient_data.At(i)->visit_history.At(j).sickness;
                    v_tmp.description = resource_pool_->patient_data.At(i)->visit_history.At(j).description;
                    v_tmp.registration_time = resource_pool_->patient_data.At(i)->visit_history.At(j).registration_time;
                    v_tmp.doctor = resource_pool_->patient_data.At(i)->visit_history.At(j).doctor;
                    v_tmp.medicine_information = resource_pool_->patient_data.At(i)->visit_history.At(j).medicine_information;
                    p_tmp.visit_history.InsertTail(v_tmp);
                }*/

                copy.InsertTail(p_tmp);
            }

            copy.Sort(util::ComparePatientID);

            // Print 1 line
            for (int i = lines * current_page_index; i < resource_pool_->patient_data.Size(); ++i)
            {
                --lines;

                Patient p_tmp = copy.At(i);
                std::cout << util::FitString(p_tmp.id, 7) << " ";  // ID
                std::cout << util::FitString(p_tmp.first_name, 11) << " ";  // First Name
                std::cout << util::FitString(p_tmp.last_name, 11) << " ";  // Last Name
                std::cout << util::FitString(std::to_string(p_tmp.age), 3) << " ";  // Age
                std::cout << util::FitString(std::string(1, p_tmp.gender), 7) << " ";  // Gender
                std::cout << util::FitString(p_tmp.contact_number, 15) << " ";  // Contact
                std::cout << util::FitString(p_tmp.address, 23) << " ";  // Address
                std::cout << util::FitString(p_tmp.disability, 11) << " ";  // Disability
                std::cout << util::FitString(std::to_string(p_tmp.visit_history.Size()), 7) << std::endl;  // Visits

                if (lines == 0)
                    break;
            }

            while (lines > 0)
            {
                std::cout << std::endl;
                --lines;
            }

            // "Footer" text
            if (invalid_input)
            {
                std::cout << "========== Invalid Input ==========" << std::endl;
                invalid_input = false;
            }
            else
                std::cout << std::endl;
            std::cout << "Page " << current_page_index + 1 << " of " << page_count << std::endl;
            std::cout << "\"<\" Back | \"!\" Exit | \">\" Forward" << std::endl;
            std::cout << "Input: ";
            std::cin >> input;
            std::cin.ignore();

            switch (input[0])
            {
                case '<':
                    if (current_page_index < page_count - 1)
                        invalid_input = true;
                    else
                        --current_page_index;
                    break;
                case '!':
                    exit = true;
                    break;
                case '>':
                    if (current_page_index > page_count - 2)
                        invalid_input = true;
                    else
                        ++current_page_index;
                    break;
                default:
                    invalid_input = true;
                    break;
            }
        }
    }
} // namespace pms