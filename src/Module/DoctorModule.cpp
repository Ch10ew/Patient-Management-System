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
                return SearchByID(search_term);
                break;
            case 1:  // Name
                search_term = PromptSearch("name");
                return SearchByName(search_term);
                break;
            case 2:  // Age
                search_term = PromptSearch("age");
                return SearchByAge(search_term);
                break;
            case 3:  // Gender
                search_term = PromptSearch("gender");
                return SearchByGender(search_term);
                break;
            case 4:  // Contact Number
                search_term = PromptSearch("contact number");
                return SearchByContactNumber(search_term);
                break;
            case 5:  // Address
                search_term = PromptSearch("address");
                return SearchByAddress(search_term);
                break;
            case 6:  // Disability
                search_term = PromptSearch("disability");
                return SearchByDisability(search_term);
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
                return SearchBySickness(search_term);
                break;
            case 1:  // Description
                search_term = PromptSearch("description");
                return SearchByDescription(search_term);
                break;
            case 2:  // Visit Date
                search_term = PromptSearch("visit date");
                return SearchByVisitDate(search_term);
                break;
            case 3:  // Doctor ID
                search_term = PromptSearch("doctor id");
                return SearchByDoctorID(search_term);
                break;
            case 4:  // Doctor Name
                search_term = PromptSearch("doctor name");
                return SearchByDoctorName(search_term);
                break;
            case 5:  // Medicine Information
                search_term = PromptSearch("medicine information");
                return SearchByMedicineInformation(search_term);
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

    std::shared_ptr<Patient> DoctorModule::SearchByID(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>(search_term),
                util::MatchPatientID,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByName(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", search_term, search_term, 0, 0, "", "", "", 0),
                util::MatchPatientName,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByAge(std::string search_term)
    {
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

        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", "", "", search_age, 0, "", "", "", 0),
                util::MatchPatientAge,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByGender(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", "", "", 0, search_term[0], "", "", "", 0),
                util::MatchPatientGender,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByContactNumber(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", "", "", 0, 0, search_term, "", "", 0),
                util::MatchPatientContactNumber,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByAddress(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", "", "", 0, 0, "", search_term, "", 0),
                util::MatchPatientAddress,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByDisability(std::string search_term)
    {
        List<int> matching_indices;

        // Get matches
        for (int pos = -1; pos < resource_pool_->patient_data.Size(); )
        {
            // Add index into matching list
            if (pos >= 0)
                matching_indices.InsertTail(pos);
            
            // Update position
            pos = resource_pool_->patient_data.Search(
                std::make_shared<Patient>("", "", "", 0, 0, "", "", search_term, 0),
                util::MatchPatientDisability,
                pos + 1
            );

            if (pos == -1)
                break;
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_indices.Size(); ++i)
        {
            std::string tmp;
            
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->id;
            tmp += " - ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->first_name;
            tmp += " ";
            tmp += resource_pool_->patient_data.At(matching_indices.At(i))->last_name;

            search_matches[i] = tmp;
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchBySickness(std::string search_term)
    {
        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit(search_term, "", 0, nullptr, ""),
                    util::MatchVisitSickness,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByDescription(std::string search_term)
    {
        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit("", search_term, 0, nullptr, ""),
                    util::MatchVisitDescription,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByVisitDate(std::string search_term)
    {
        time_t search_time;

        // Guard invalid search time
        try
        {
            search_time = ctimew::GetTimeTFromString(search_term);
        }
        catch(...)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit("", "", search_time, nullptr, ""),
                    util::MatchVisitVisitDate,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByDoctorID(std::string search_term)
    {
        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit("", "", 0, std::make_shared<Doctor>(search_term), ""),
                    util::MatchVisitDoctorID,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByDoctorName(std::string search_term)
    {
        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit("", "", 0, std::make_shared<Doctor>("", "", "", search_term, search_term, ""), ""),
                    util::MatchVisitDoctorName,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
        }
        catch(...)
        {
            return nullptr;
        }
    }

    std::shared_ptr<Patient> DoctorModule::SearchByMedicineInformation(std::string search_term)
    {
        List<int> matching_indices;
        List<std::string> matching_strings;

        // Loop through patients
        std::string matching_visit_history;
        bool current_patient_has_match;
        for (int pos = 0; pos < resource_pool_->patient_data.Size(); ++pos)
        {
            matching_visit_history = "";
            current_patient_has_match = false;
            std::shared_ptr<Patient> p_tmp = resource_pool_->patient_data.At(pos);
            
            // Get matches
            for (int i = -1; i < p_tmp->visit_history.Size(); )
            {
                List<Visit> vh_tmp = p_tmp->visit_history;
                // Add match into matching list
                if (i >= 0)
                {
                    // Format
                    // 2021-09-26 11:09:00 - Fever | Unspecified | D0001 - Hafiz bin Abdul | Paracetamol
                    matching_visit_history += "\t";
                    matching_visit_history += ctimew::FormatTime(ctimew::StructTM(vh_tmp.At(i).registration_time));
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).sickness;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).description;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).doctor->id;
                    matching_visit_history += " - ";
                    matching_visit_history += vh_tmp.At(i).doctor->first_name;
                    matching_visit_history += " ";
                    matching_visit_history += vh_tmp.At(i).doctor->last_name;
                    matching_visit_history += " | ";
                    matching_visit_history += vh_tmp.At(i).medicine_information;

                    matching_visit_history += "\n";  // newline
                    current_patient_has_match = true;
                }

                // Update position
                i = p_tmp->visit_history.Search(
                    Visit("", "", 0, nullptr, search_term),
                    util::MatchVisitMedicineInformation,
                    i + 1
                );

                if (i == -1)
                    i = p_tmp->visit_history.Size();
                }
            
            // Add matches to lists
            if (current_patient_has_match)
            {
                std::string tmp;
                tmp += p_tmp->id;
                tmp += " - ";
                tmp += p_tmp->first_name;
                tmp += " ";
                tmp += p_tmp->last_name;
                tmp += "\n";

                matching_visit_history = tmp + matching_visit_history;

                matching_indices.InsertTail(pos);
                matching_strings.InsertTail(matching_visit_history);
            }
        }

        // Add matches as options into array
        std::string* search_matches = new std::string[matching_indices.Size()];
        for (int i = 0; i < matching_strings.Size(); ++i)
        {
            search_matches[i] = matching_strings.At(i);
        }

        if (matching_indices.Size() == 0)
        {
            std::cout << " - No results found - " << std::endl;
            return nullptr;
        }

        int option = util::Menu("Search Results", search_matches, matching_indices.Size());

        // Free pointer above
        delete[] search_matches;

        // Try to return the pointer
        try
        {
            return resource_pool_->patient_data.At(matching_indices.At(option));
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
        std::cout << std::endl;

    }
} // namespace pms