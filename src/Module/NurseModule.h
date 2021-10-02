#ifndef PMS_NURSE_MODULE_H
#define PMS_NURSE_MODULE_H

#include "Module.h"
#include "../Structures/List.h"
#include "../Structures/Role.h"
#include "../Structures/Patient.h"

#include <memory>
#include <string>

namespace pms
{
    class NurseModule : public Module
    {
        public:
            NurseModule(std::shared_ptr<ResourcePool> resource_pool);
            void Run();
            void Login();
            void Menu();

        private:
            void AddPatient();
            void PrintPatientList();
            std::string GeneratePatientID(std::string prefix, int length, int list_size);
            void Pagination();
            std::shared_ptr<Patient> Search();
            

        private:
            bool logged_in_;
            bool exit_;
            std::shared_ptr<Nurse> logged_in_nurse_;
            
        
    };
} // namespace pms

#endif // PMS_NURSE_MODULE_H
