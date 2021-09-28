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
            std::shared_ptr<Patient> Search();
            std::shared_ptr<Patient> SearchByVisitHistory();
            std::string PromptSearch(std::string attribute);
            void Pagination();
        
        private:
            template <class Compare>
            std::shared_ptr<Patient> SearchBy(Patient search_term, Compare comp);
            
            template <class Compare>
            std::shared_ptr<Patient> SearchBy(Visit search_term, Compare comp);

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
    std::shared_ptr<Patient> DoctorModule::SearchBy(Visit search_term, Compare comp)
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
                    comp,
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

} // namespace pms

#endif // PMS_DOCTOR_MODULE_H
