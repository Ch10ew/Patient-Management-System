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

        private:
            bool logged_in_;
            bool exit_;
            std::shared_ptr<Doctor> logged_in_doctor_;
    };
} // namespace pms

#endif // PMS_DOCTOR_MODULE_H
