#ifndef PMS_DOCTOR_MODULE_H
#define PMS_DOCTOR_MODULE_H

#include "UI.h"
#include "../Structures/List.h"
#include "../Structures/Patient.h"

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
            std::shared_ptr<Patient> SearchByID(std::string search_term);
            std::shared_ptr<Patient> SearchByName(std::string search_term);
            std::shared_ptr<Patient> SearchByAge(std::string search_term);
            std::shared_ptr<Patient> SearchByGender(std::string search_term);
            std::shared_ptr<Patient> SearchByContactNumber(std::string search_term);
            std::shared_ptr<Patient> SearchByAddress(std::string search_term);
            std::shared_ptr<Patient> SearchByDisability(std::string search_term);
            std::shared_ptr<Patient> SearchBySickness(std::string search_term);
            std::shared_ptr<Patient> SearchByDescription(std::string search_term);
            std::shared_ptr<Patient> SearchByVisitDate(std::string search_term);
            std::shared_ptr<Patient> SearchByDoctorID(std::string search_term);
            std::shared_ptr<Patient> SearchByDoctorName(std::string search_term);
            std::shared_ptr<Patient> SearchByMedicineInformation(std::string search_term);
            void Pagination();

        private:
            bool logged_in_;
            bool exit_;
            std::shared_ptr<Doctor> logged_in_doctor_;
    };
} // namespace pms

#endif // PMS_DOCTOR_MODULE_H
