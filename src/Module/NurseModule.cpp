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
#include <ostream>

namespace pms
{
    bool MatchAccount(std::shared_ptr<Nurse> n1, std::shared_ptr<Nurse> n2)
    {
        return (n1->username == n2->username) && (n1->password == n2->password);
    }

    NurseModule::NurseModule(std::shared_ptr<ResourcePool> resource_pool)
    : Module(resource_pool)
    {
        module_option_text_ = "Nurse Login";
    }

    /**
     * @brief Entry point of `NurseModule`. Loops `Login()` (and optionally `Menu()`) until exit flag is set.
     */
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

    /**
     * @brief Prompts for username and password. Then, tries to find a match.
     * 
     * Sets logged in flag if successful. Also sets the logged in patient pointer.
     */
    void NurseModule::Login()
    {
        resource_pool_->waiting_data.Sort(util::ComparePriorityAsc2);
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

    /**
     * @brief Allows the doctor to add a new patient, add an existing patient to waiting list print patient list, modify a patient record, 
     * see the patient list in pagination, call a patient search for a specific patient and and view the waiting list in pagination.
     */
    void NurseModule::Menu()
    {
        bool exit = false;

        std::string* option_text = new std::string[7];
        option_text[0] = "Add a new patient to waiting list";     
        option_text[1] = "Add existing patient to waiting list";  
        option_text[2] = "Modify patient record";                 
        option_text[3] = "View patient list in pagination";       
        option_text[4] = "Call a patient";                        
        option_text[5] = "Search for patient record";             
        option_text[6] = "View waiting list in pagination";   
        while (!exit)
        {
            int option = pms::util::Menu("Welcome, " + logged_in_nurse_->first_name, option_text, 7);

            // Run selected option
            std::cout << std::endl;
            std::cout << std::endl;
            switch (option)
            {
                case 0:
                    std::cout << " = Add a new patient = " << std::endl;
                    std::cout << std::endl;
                    AddPatient();
                    break;
                case 1:
                    std::cout << " = Add patient to waiting list = " << std::endl;
                    std::cout << std::endl;
                    AddtoWaiting(Search());
                    break;
                case 2:
                    std::cout << " = Search & Modify = " << std::endl;
                    std::cout << std::endl;
                    Modify(Search());
                    break;
                case 3:
                    std::cout << " = Print Patient List = " << std::endl;
                    std::cout << std::endl;
                    PromptPaginationList();
                    break;
                case 4:
                    std::cout << " = Call a patinet = " << std::endl;
                    std::cout << std::endl;
                    CallPatient(resource_pool_->waiting_data.Poll());
                    break;
                case 5:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    PrintPatient(Search());
                    break;
                case 6:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    promptWaitingPagination();
                    break;
                case 7:
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
    /**
     * @brief Add a patient to the database.
     */
    void NurseModule::AddPatient()
    {
        std::string id;
        std::string first_name;
        std::string last_name;
        int age;
        char gender;
        std::string contact_number;
        std::string address;
        std::string disability = "";
        int priority;
        bool invalid_input = false;

        std::string* input_text = new std::string[8];
        input_text[0] = "First Name: ";
        input_text[1] = "Last Name: ";
        input_text[2] = "Age: ";
        input_text[3] = "Gender(F/M): ";
        input_text[4] = "Contact Number: ";
        input_text[5] = "Address: ";
        input_text[6] = "Disability: ";
        input_text[7] = "Priority Index: ";

        for(int i = 0; i < 8; i++){
            std::string tmp;
            std::string tmp2;
            std::string tmp3;
            if (invalid_input)
            {
                std::cout << "\n" << "========== Invalid " + input_text[i] + " ==========" << std::endl;
                invalid_input = false;
            }
                    
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
                        priority = std::stoi(tmp3);
                        if (priority < 0 || priority > 5){
                            invalid_input = true;
                            i--;
                        }
                    }
                    catch(...)
                    {
                        invalid_input = true;
                        i--;
                    }
                    break;
            }
        }
        delete[] input_text;
        std::string input;
        int size = resource_pool_->patient_data.Size() + 1;
        id = pms::util::GenerateId("P", 6, size);
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
        resource_pool_->waiting_data.Sort(util::ComparePriorityAsc2);
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
        std::cout << "Priority Index: " << copy.priority << std::endl;
        std::cout << "Enter anything to continue... ";
        getline(std::cin, input);
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
                std::cout << "\t" << "Visit Time: " << ctimew::FormatTime(ctimew::StructTM(copy.visit_history.At(j).registration_time)) << std::endl;
                std::cout << "\t" << "Doctor: " << copy.visit_history.At(j).doctor->id << " - " << copy.visit_history.At(j).doctor->first_name << copy.visit_history.At(j).doctor->last_name << std::endl;
                std::cout << "\t" << "Medicide Information: " << copy.visit_history.At(j).medicine_information << std::endl;
                
                if (j != copy.visit_history.Size() - 1)
                    std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    /**
     * @brief Prompts for search of a patient.
     * 
     * @return std::shared_ptr<Patient> pointer to `Patient`. May be `nullptr`.
     */
    std::shared_ptr<Patient> NurseModule::Search()
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
            case 0:  // Id
                search_term = PromptSearch("ID");
                //return SearchById(search_term);
                return SearchBy(Patient(search_term), util::MatchPatientId);
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

    /**
     * @brief General function to prompt for search of a certain attribute.
     * 
     * @param attribute To be displayed in the prompt for the user to see.
     * @return std::string search term supplied by the user
     */
    std::string NurseModule::PromptSearch(std::string attribute)
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

    /**
     * @brief Prompts for search of a patient by visit history.
     * 
     * @return std::shared_ptr<Patient> pointer to `Patient`. May be `nullptr`.
     */
    std::shared_ptr<Patient> NurseModule::SearchByVisitHistory()
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
            case 3:  // Doctor Id
                search_term = PromptSearch("doctor id");
                return SearchBy(
                    Visit("", "", 0, std::make_shared<Doctor>(search_term), ""),
                    util::MatchVisitDoctorId
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

    /**
     * @brief Prompts for the modification of the given patient. Expected to be used after `Search()` call.
     * 
     * Shows that there are no results found if `nullptr` is supplied.
     * 
     * @param patient_ptr Pointer to `Patient` to be modified.
     */
    void NurseModule::Modify(std::shared_ptr<pms::Patient> patient_ptr)
    {
        util::ClearScreen();
        
        std::string input;
        if (!patient_ptr)
        {
            std::cout << std::endl;
            std::cout << " = Search Results =" << std::endl;
            std::cout << std::endl;
            std::cout << " - No results found - " << std::endl;
            std::cout << std::endl;
            std::cout << "Enter anything to continue... ";
            getline(std::cin, input);
            return;
        }

        bool exit = false;
        int option;
        std::string* option_text = new std::string[9];
        option_text[0] = "Modify first name";
        option_text[1] = "Modify last name";
        option_text[2] = "Modify age";
        option_text[3] = "Modify gender";
        option_text[4] = "Modify contact number";
        option_text[5] = "Modify address";
        option_text[6] = "Modify disability";
        option_text[7] = "Modify priority";
        option_text[8] = "Modify visit history";

        while (!exit)
        {
            util::ClearScreen();

            // Print current patient details
            std::cout << std::endl;
            std::cout << patient_ptr->id << " - " << patient_ptr->first_name << " " << patient_ptr->last_name << std::endl;
            std::cout << "Age: " << patient_ptr->age << std::endl;
            std::cout << "Gender: " << patient_ptr->gender << std::endl;
            std::cout << "Contact Number: " << patient_ptr->contact_number << std::endl;
            std::cout << "Address: " << patient_ptr->address << std::endl;
            std::cout << "Disability: " << patient_ptr->disability << std::endl;
            std::cout << "Priority: " << patient_ptr->priority << std::endl;
            std::cout << "Visit History: " << std::endl;
            for (int j = 0; j < patient_ptr->visit_history.Size(); ++j)
            {
                std::cout << "\t" << "Visit #" << j + 1 << std::endl;
                std::cout << "\t" << "Sickness: " << patient_ptr->visit_history.At(j).sickness << std::endl;
                std::cout << "\t" << "Description: " << patient_ptr->visit_history.At(j).description << std::endl;
                std::cout << "\t" << "Visit Time: " << ctimew::FormatTime(ctimew::StructTM(patient_ptr->visit_history.At(j).registration_time)) << std::endl;
                std::cout << "\t" << "Doctor: " << patient_ptr->visit_history.At(j).doctor->id << " - " << patient_ptr->visit_history.At(j).doctor->first_name << patient_ptr->visit_history.At(j).doctor->last_name << std::endl;
                std::cout << "\t" << "Medicide Information: " << patient_ptr->visit_history.At(j).medicine_information << std::endl;
                
                if (j != patient_ptr->visit_history.Size() - 1)
                    std::cout << std::endl;
            }
            std::cout << std::endl;

            // Prompt for attribute
            option = util::Menu("Select attribute to modify", option_text, 9, false);
            
            // Run based on option selected
            int age = 0, priority = 0;
            std::string data;

            bool invalid_input = false;
            switch (option)
            {
                case 0:  // First Name
                    patient_ptr->first_name = PromptModify("first name");
                    break;
                case 1:  // Last Name
                    patient_ptr->last_name = PromptModify("last name");
                    break;
                case 2:  // Age
                    do
                    {
                        if (invalid_input)
                        {
                            std::cout << "========== Invalid Input ==========" << std::endl;
                            invalid_input = false;
                        }

                        data = PromptModify("age");                        
                        try
                        {
                            age = std::stoi(data);
                        }
                        catch (...)
                        {
                            invalid_input = true;
                        }

                        if (age < 0 || age > 150)
                            invalid_input = true;
                    }
                    while (invalid_input);

                    patient_ptr->age = age;
                    break;
                case 3:  // Gender
                    do
                    {
                        if (invalid_input)
                        {
                            std::cout << "========== Invalid Input ==========" << std::endl;
                            invalid_input = false;
                        }

                        data = PromptModify("gender");
                        if (data.length() > 2 || data.length() == 0)
                            invalid_input = true;
                        
                        if (data[0] != 'M' && data[0] != 'F')
                            invalid_input = true;
                    }
                    while (invalid_input);

                    patient_ptr->gender = data[0];
                    break;
                case 4:  // Contact Number
                    do
                    {
                        if (invalid_input)
                        {
                            std::cout << "========== Invalid Input ==========" << std::endl;
                            invalid_input = false;
                        }

                        data = PromptModify("contact number");
                        if (data.find_first_not_of("+-#*()0123456789") != std::string::npos)
                            invalid_input = true;
                    }
                    while (invalid_input);

                    patient_ptr->contact_number = data;
                    break;
                case 5:  // Address
                    patient_ptr->address = PromptModify("address");
                    break;
                case 6:  // Disability
                    patient_ptr->disability = PromptModify("disability");
                    break;
                case 7:  // Priority
                    do
                    {
                        if (invalid_input)
                        {
                            std::cout << "========== Invalid Input ==========" << std::endl;
                            invalid_input = false;
                        }

                        data = PromptModify("priority");                        
                        try
                        {
                            priority = std::stoi(data);
                        }
                        catch (...)
                        {
                            invalid_input = true;
                        }
                    }
                    while (invalid_input);

                    patient_ptr->priority = priority;
                    break;
                case 8:  // Visit history
                    ModifyVisitHistory(patient_ptr);
                    break;
                case 9:  // Exit
                    exit = true;
                    break;
            }
        }

        // Free pointer above
        delete[] option_text;
    }
    
    /**
     * @brief General function to prompt for modification of a certain attribute.
     * 
     * @param attribute To be displayed in the prompt for the user to see.
     * @return std::string data supplied by the user
     */
    std::string NurseModule::PromptModify(std::string attribute)
    {
        std::string input_string;

        // Display options
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << " = Modify " << attribute << " = " << std::endl;
        std::cout << std::endl;
        if (attribute == "visit date")
        {
            std::cout << "Date format is YYYY/MM/DD HH:MM:SS." << std::endl;
            std::cout << "New data: ";
        }
        else if (attribute == "priority")
        {
            std::cout << "0 for high priority, 5 for low priority." << std::endl;
            std::cout << "New data: ";
        }
        else
        {
            std::cout << "New data: ";
        }
        getline(std::cin, input_string);

        return input_string;
    }

    /**
     * @brief Prompts for the sorting method for pagination.
     */
    void NurseModule::PromptPagination()
    {
        std::string* option_text = new std::string[18];
        option_text[0] = "Sort by Id (Ascending)";
        option_text[1] = "Sort by Id (Descending)";
        option_text[2] = "Sort by first name (Ascending)";
        option_text[3] = "Sort by first name (Descending)";
        option_text[4] = "Sort by last name (Ascending)";
        option_text[5] = "Sort by last name (Descending)";
        option_text[6] = "Sort by age (Ascending)";
        option_text[7] = "Sort by age (Descending)";
        option_text[8] = "Sort by gender (Ascending)";
        option_text[9] = "Sort by gender (Descending)";
        option_text[10] = "Sort by contact (Ascending)";
        option_text[11] = "Sort by contact (Descending)";
        option_text[12] = "Sort by address (Ascending)";
        option_text[13] = "Sort by address (Descending)";
        option_text[14] = "Sort by disability (Ascending)";
        option_text[15] = "Sort by disability (Descending)";
        option_text[16] = "Sort by visit count (Ascending)";
        option_text[17] = "Sort by visit count (Descending)";

        // Prompt for search criteria
        int option = util::Menu("Pagination for patient", option_text, 18);

        // Free pointer above
        delete[] option_text;
        
        // Run based on option selected
        switch (option)
        {
            case 0:
                Pagination(util::ComparePatientIdAsc);
                break;
            case 1:
                Pagination(util::ComparePatientIdDesc);
                break;
            case 2:
                Pagination(util::ComparePatientFirstNameAsc);
                break;
            case 3:
                Pagination(util::ComparePatientFirstNameDesc);
                break;
            case 4:
                Pagination(util::ComparePatientLastNameAsc);
                break;
            case 5:
                Pagination(util::ComparePatientLastNameDesc);
                break;
            case 6:
                Pagination(util::ComparePatientAgeAsc);
                break;
            case 7:
                Pagination(util::ComparePatientAgeDesc);
                break;
            case 8:
                Pagination(util::ComparePatientGenderAsc);
                break;
            case 9:
                Pagination(util::ComparePatientGenderDesc);
                break;
            case 10:
                Pagination(util::ComparePatientContactNumberAsc);
                break;
            case 11:
                Pagination(util::ComparePatientContactNumberDesc);
                break;
            case 12:
                Pagination(util::ComparePatientAddressAsc);
                break;
            case 13:
                Pagination(util::ComparePatientAddressDesc);
                break;
            case 14:
                Pagination(util::ComparePatientDisabilityAsc);
                break;
            case 15:
                Pagination(util::ComparePatientDisabilityDesc);
                break;
            case 16:
                Pagination(util::ComparePatientVisitsAsc);
                break;
            case 17:
                Pagination(util::ComparePatientVisitsDesc);
                break;
            case 18:
                break;
        }
    }

    /**
     * @brief Prompts for the modification of visit history of the given patient.
     * 
     * @param patient_ptr Pointer to `Patient` to be modified. Must not be `nullptr`.
     */
    void NurseModule::ModifyVisitHistory(std::shared_ptr<pms::Patient> patient_ptr)
    {
        // Add available visits into list
        List<std::string> visits_string;

        for (int i = 0; i < patient_ptr->visit_history.Size(); ++i)
        {
            visits_string.InsertTail(
                patient_ptr->visit_history.At(i).sickness +
                " | " +
                patient_ptr->visit_history.At(i).description +
                " | " +
                patient_ptr->visit_history.At(i).doctor->first_name +
                " " +
                patient_ptr->visit_history.At(i).doctor->last_name
            );
        }

        // Convert to string array
        std::string* visit_options = new std::string[visits_string.Size()];
        for (int i = 0; i < visits_string.Size(); ++i)
        {
            visit_options[i] = visits_string.At(i);
        }

        // Prompt for visit to modify
        int visit_index = util::Menu("Select visit to modify", visit_options, visits_string.Size());

        // Free pointer above
        delete[] visit_options;

        // Create string array for prompt
        std::string* option_text = new std::string[5];
        option_text[0] = "Modify sickness";
        option_text[1] = "Modify description";
        option_text[2] = "Modify visit date";
        option_text[3] = "Modify doctor";
        option_text[4] = "Modify medicine information";

        // Prompt for modification field
        int option = util::Menu("Select attribute to modify", option_text, 8);

        // Free pointer above
        delete[] option_text;
    }

    /**
     * @brief Prompts for the sorting method for pagination for patients.
     */
    void NurseModule::PromptPaginationList()
    {
        std::string* option_text = new std::string[18];
        option_text[0] = "Sort by Id (Ascending)";
        option_text[1] = "Sort by Id (Descending)";
        option_text[2] = "Sort by first name (Ascending)";
        option_text[3] = "Sort by first name (Descending)";
        option_text[4] = "Sort by last name (Ascending)";
        option_text[5] = "Sort by last name (Descending)";
        option_text[6] = "Sort by age (Ascending)";
        option_text[7] = "Sort by age (Descending)";
        option_text[8] = "Sort by gender (Ascending)";
        option_text[9] = "Sort by gender (Descending)";
        option_text[10] = "Sort by contact (Ascending)";
        option_text[11] = "Sort by contact (Descending)";
        option_text[12] = "Sort by address (Ascending)";
        option_text[13] = "Sort by address (Descending)";
        option_text[14] = "Sort by disability (Ascending)";
        option_text[15] = "Sort by disability (Descending)";
        option_text[16] = "Sort by visit count (Ascending)";
        option_text[17] = "Sort by visit count (Descending)";

        // Prompt for search criteria
        int option = util::Menu("Pagination for patient", option_text, 18);

        // Free pointer above
        delete[] option_text;
        
        // Run based on option selected
        switch (option)
        {
            case 0:
                PaginationList(util::ComparePatientIdAsc);
                break;
            case 1:
                PaginationList(util::ComparePatientIdDesc);
                break;
            case 2:
                PaginationList(util::ComparePatientFirstNameAsc);
                break;
            case 3:
                PaginationList(util::ComparePatientFirstNameDesc);
                break;
            case 4:
                PaginationList(util::ComparePatientLastNameAsc);
                break;
            case 5:
                PaginationList(util::ComparePatientLastNameDesc);
                break;
            case 6:
                PaginationList(util::ComparePatientAgeAsc);
                break;
            case 7:
                PaginationList(util::ComparePatientAgeDesc);
                break;
            case 8:
                PaginationList(util::ComparePatientGenderAsc);
                break;
            case 9:
                PaginationList(util::ComparePatientGenderDesc);
                break;
            case 10:
                PaginationList(util::ComparePatientContactNumberAsc);
                break;
            case 11:
                PaginationList(util::ComparePatientContactNumberDesc);
                break;
            case 12:
                PaginationList(util::ComparePatientAddressAsc);
                break;
            case 13:
                PaginationList(util::ComparePatientAddressDesc);
                break;
            case 14:
                PaginationList(util::ComparePatientDisabilityAsc);
                break;
            case 15:
                PaginationList(util::ComparePatientDisabilityDesc);
                break;
            case 16:
                PaginationList(util::ComparePatientVisitsAsc);
                break;
            case 17:
                PaginationList(util::ComparePatientVisitsDesc);
                break;
            case 18:
                break;
        }
    }

    /**
     * @brief Calling and removing a patient from the first of the waiting list sorted with priority index.
     * 
     * @param Pointer to `Patient` to be called.
     */
    void NurseModule::CallPatient(std::shared_ptr<Waiting> waiting_ptr){
        
        std::string input;
        
        if (!waiting_ptr)
        {
            std::cout << std::endl;
            std::cout << " = Search Results =" << std::endl;
            std::cout << std::endl;
            std::cout << " - No results found - " << std::endl;
            std::cout << std::endl;
            std::cout << "Enter anything to continue... ";
            getline(std::cin, input);
            return;
        }
        std::shared_ptr<Patient> patient_ptr = SearchBy(Patient(waiting_ptr->id), util::MatchPatientId);
        if(!patient_ptr)
            return;
        Patient copy = *patient_ptr;
        std::cout << "Calling the following patient" << std::endl;
        std::cout << std::endl;
        std::cout << copy.id << " - " << copy.first_name << " " << copy.last_name << std::endl;
        std::cout << "Age: " << copy.age << std::endl;
        std::cout << "Gender: " << copy.gender << std::endl;
        std::cout << "Contact Number: " << copy.contact_number << std::endl;
        std::cout << "Address: " << copy.address << std::endl;
        std::cout << "Disability: " << copy.disability << std::endl;
        std::cout << "Priority: " << copy.priority << std::endl;
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
        std::cout << "The patient is removed from the waiting list" << std::endl;
        std::cout << "Enter anything to continue... ";
        getline(std::cin, input);
    }

    /**
     * @brief Prints the given patient. Expected to be used after a `Search()` call.
     * 
     * @param patient_ptr Pointer to `Patient` to be printed.
     */
    void NurseModule::PrintPatient(std::shared_ptr<Patient> patient_ptr)
    {
        util::ClearScreen();
        resource_pool_->waiting_data.Sort(util::ComparePriorityAsc2);
        std::string input;
        if (!patient_ptr)
        {
            std::cout << std::endl;
            std::cout << " = Search Results =" << std::endl;
            std::cout << std::endl;
            std::cout << " - No results found - " << std::endl;
            std::cout << std::endl;
            std::cout << "Enter anything to continue... ";
            getline(std::cin, input);
            return;
        }
        
        Patient copy = *patient_ptr;

        std::cout << std::endl;
        std::cout << " = Search Results =" << std::endl;
        std::cout << std::endl;
        std::cout << copy.id << " - " << copy.first_name << " " << copy.last_name << std::endl;
        std::cout << "Age: " << copy.age << std::endl;
        std::cout << "Gender: " << copy.gender << std::endl;
        std::cout << "Contact Number: " << copy.contact_number << std::endl;
        std::cout << "Address: " << copy.address << std::endl;
        std::cout << "Disability: " << copy.disability << std::endl;
        std::cout << "Priority: " << copy.priority << std::endl;
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
        std::cout << "Enter anything to continue... ";
        getline(std::cin, input);

    }
    
    /**
     * @brief Add an existing patient to waiting list.
     * 
     * @param Pointer to `Patient` to be called.
     */
    void NurseModule::AddtoWaiting(std::shared_ptr<Patient> patient_ptr){
        util::ClearScreen();

        std::string input, enter;
        int priority;
        bool exit = false, invalid_input = false;
        if (!patient_ptr)
        {
            std::cout << std::endl;
            std::cout << " = Search Results =" << std::endl;
            std::cout << std::endl;
            std::cout << " - No results found - " << std::endl;
            std::cout << std::endl;
            std::cout << "Enter anything to continue... ";
            getline(std::cin, input);
            return;
        }
        std::cout << "Patient found:"  << std::endl;
        PrintPatient(patient_ptr);
        while (!exit) {
            
            if (invalid_input){
                std::cout << "=== Invalid Input ===\n" << std::endl;
                invalid_input = false;
            }
            std::cout << "Enter priority index ( 1-5 ), enter (x) to exit: ";
            getline(std::cin, input);
            if(input == "x")
                return;
            try{
                priority = std::stoi(input);
                if (priority < 0 || priority > 5)
                    invalid_input = true;
            }catch(...){
                invalid_input = true;
            }

            if (!invalid_input){
                time_t time_temp = ctimew::Time();
                resource_pool_->waiting_data.InsertTail(std::make_shared<Waiting>(
                    patient_ptr->id,
                    patient_ptr->first_name,
                    patient_ptr->last_name,
                    priority,
                    time_temp
                ));
                resource_pool_->waiting_data.Sort(util::ComparePriorityAsc2);
                std::cout << "Patient is added to the wating list" << std::endl;
                std::cout << "Patient ID: " << patient_ptr->id << std::endl;
                std::cout << "First Name: " << patient_ptr->first_name << std::endl;
                std::cout << "Last Name: " << patient_ptr-> last_name << std::endl;
                std::cout << "Priority: " << priority << std::endl;
                std::cout << "Registration Time: " << ctimew::FormatTime(ctimew::StructTM(time_temp)) << std::endl;
                std::cout << "Enter anything to continue... ";
                getline(std::cin, enter);
                return;
                
            }
        }
    }

    /**
     * @brief Prompts for the sorting method for pagination for waiting list.
     */
    void NurseModule::promptWaitingPagination(){
        std::string* option_text = new std::string[10];
        option_text[0] = "Sort by Id (Ascending)";
        option_text[1] = "Sort by Id (Descending)";
        option_text[2] = "Sort by first name (Ascending)";
        option_text[3] = "Sort by first name (Descending)";
        option_text[4] = "Sort by last name (Ascending)";
        option_text[5] = "Sort by last name (Descending)";
        option_text[6] = "Sort by registered time (Ascending)";
        option_text[7] = "Sort by registered time (Descending)";
        option_text[8] = "Sort by priority (Ascending)";
        option_text[9] = "Sort by priority (Descending)";
        // Prompt for search criteria
        int option = util::Menu("Pagination for patient", option_text, 10);

        // Free pointer above
        delete[] option_text;
        
        // Run based on option selected
        switch (option)
        {
            case 0:
                PaginationWaitngList(util::CompareWaitingIdAsc);
                break;
            case 1:
                PaginationWaitngList(util::CompareWaitingIdDesc);
                break;
            case 2:
                PaginationWaitngList(util::CompareWaitingFirstNameAsc);
                break;
            case 3:
                PaginationWaitngList(util::CompareWaitingFirstNameDesc);
                break;
            case 4:
                PaginationWaitngList(util::CompareWaitingLastNameAsc);
                break;
            case 5:
                PaginationWaitngList(util::CompareWaitingLastNameDesc);
                break;
            case 6:
                PaginationWaitngList(util::CompareWaitingTimeAsc);
                break;
            case 7:
                PaginationWaitngList(util::CompareWaitingTimeDesc);
                break;
            case 8:
                PaginationWaitngList(util::ComparePriorityAsc);
                break;
            case 9:
                PaginationWaitngList(util::ComparePriorityDesc);
                break;
            
        }
        
    }

} // namespace pms