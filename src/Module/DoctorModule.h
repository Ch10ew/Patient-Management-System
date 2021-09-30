#ifndef PMS_DOCTOR_MODULE_H
#define PMS_DOCTOR_MODULE_H

#include "UI.h"
#include "../Structures/List.h"
#include "../Structures/Patient.h"
#include "../Util/Util.h"

#include <memory>
#include <string>

namespace pms
{
    bool MatchAccount(std::shared_ptr<Doctor> d1, std::shared_ptr<Doctor> d2);

    class DoctorModule : public UI
    {
        public:
            DoctorModule(std::shared_ptr<ResourcePool> resource_pool);
            void Run();
            void Login();
            void Menu();

        private:
            void PrintPatientList();
            void PrintPatient(std::shared_ptr<Patient> patient_ptr);
            void Modify(std::shared_ptr<pms::Patient> patient_ptr);
            void ModifyVisitHistory(std::shared_ptr<pms::Patient> patient_ptr);
            std::shared_ptr<Patient> Search();
            std::shared_ptr<Patient> SearchByVisitHistory();
            std::string PromptModify(std::string attribute);
            std::string PromptSearch(std::string attribute);
            void PromptPagination();
        
        private:
            template <class Compare>
            std::shared_ptr<Patient> SearchBy(Patient search_term, Compare comp);
            
            template <class Compare>
            std::shared_ptr<Patient> SearchBy(Visit search_term, Compare comp);

            template <class Compare>
            void Pagination(Compare func);

        private:
            bool logged_in_;
            bool exit_;
            std::shared_ptr<Doctor> logged_in_doctor_;
    };

    template <class Compare>
    std::shared_ptr<Patient> DoctorModule::SearchBy(Patient search_term, Compare comp)
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
                comp,
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

            // Free pointer above
            delete[] search_matches;

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

    template <class Compare>
    std::shared_ptr<Patient> DoctorModule::SearchBy(Visit search_term, Compare func)
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
                    search_term,
                    func,
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

            // Free pointer above
            delete[] search_matches;

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

    template <class Compare>
    void DoctorModule::Pagination(Compare func)
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

            util::ClearScreen();

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
                copy.InsertTail(p_tmp);
            }

            copy.Sort(func);

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

#endif // PMS_DOCTOR_MODULE_H
