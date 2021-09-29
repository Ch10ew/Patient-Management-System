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
                    Modify(Search());
                    break;
                case 2:
                    std::cout << " = Pagination for patient = " << std::endl;
                    std::cout << std::endl;
                    PromptPagination();
                    break;
                case 3:
                    std::cout << " = Search & View = " << std::endl;
                    std::cout << std::endl;
                    Search();
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

    void DoctorModule::Modify(std::shared_ptr<pms::Patient> patient_ptr)
    {
        bool exit = false;
        int option;
        std::string* option_text = new std::string[8];
        option_text[0] = "Modify first name";
        option_text[1] = "Modify last name";
        option_text[2] = "Modify age";
        option_text[3] = "Modify gender";
        option_text[4] = "Modify contact number";
        option_text[5] = "Modify address";
        option_text[6] = "Modify disability";
        option_text[7] = "Modify visit history";

        while (!exit)
        {
            // Prompt for search criteria
            option = util::Menu("Search", option_text, 8);

            // Print current patient details
            std::cout << patient_ptr->id << " - " << patient_ptr->first_name << " " << patient_ptr->last_name << std::endl;
            std::cout << "Age: " << patient_ptr->age << std::endl;
            std::cout << "Gender: " << patient_ptr->gender << std::endl;
            std::cout << "Contact Number: " << patient_ptr->contact_number << std::endl;
            std::cout << "Address: " << patient_ptr->address << std::endl;
            std::cout << "Disability: " << patient_ptr->disability << std::endl;
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
            
            // Run based on option selected
            int age = 0;
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
                            std::cout << "========== Invalid Input ==========" << std::endl;

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
                            std::cout << "========== Invalid Input ==========" << std::endl;

                        data = PromptModify("gender");
                        if (data.length() > 1 || data.length() == 0)
                            invalid_input = true;
                        
                        if (data[0] != 'M' || data[0] != 'F')
                            invalid_input = true;
                    }
                    while (invalid_input);

                    patient_ptr->gender = data[0];
                    break;
                case 4:  // Contact Number
                    do
                    {
                        if (invalid_input)
                            std::cout << "========== Invalid Input ==========" << std::endl;

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
                case 7:  // Visit history
                    ModifyVisitHistory(patient_ptr);
                    break;
                case 8:  // Exit
                    exit = true;
                    break;
            }
        }

        // Free pointer above
        delete[] option_text;
    }

    void ModifyVisitHistory(std::shared_ptr<pms::Patient> patient_ptr)
    {
        List<std::string> visits_string;

        /*for (int i = 0; i < patient_ptr->visit_history.Size(); ++i)
        {
            // how not to compile 101
        }*/

        std::string* option_text = new std::string[5];
        option_text[0] = "Modify sickness";
        option_text[1] = "Modify description";
        option_text[2] = "Modify visit date";
        option_text[3] = "Modify doctor";
        option_text[4] = "Modify medicine information";
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

    std::string DoctorModule::PromptModify(std::string attribute)
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
        else
        {
            std::cout << "New data: ";
        }
        getline(std::cin, input_string);

        return input_string;
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

    void DoctorModule::PromptPagination()
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
        int option = util::Menu("Search", option_text, 18);

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
} // namespace pms