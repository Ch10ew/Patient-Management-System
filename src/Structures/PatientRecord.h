#ifndef PMS_PATIENT_H
#define PMS_PATIENT_H

#include "Role.h"
#include "Doctor.h"

namespace pms
{
    class PatientRecord : protected Role
    {
        public:
            std::string getFirstName();
            void setFirstName(std::string first_name);
            std::string getLastName();
            void setLastName(std::string last_name);
            int getAge();
            void setAge(int age);
            char getGender();
            void setGender(char gender);
            std::string getContactNumber();
            void setContactNumber(std::string contact_number);
            std::string getAddress();
            void setAddress(std::string address);
            std::string getSickness();
            void setSickness(std::string sickness);
            std::string getDescription();
            void setDescription(std::string description);
            std::string getCurrentVisitDate();
            void setCurrentVisitDate(std::string current_visit_date);
            std::string getCurrentVisitTime();
            void setCurrentVisitTime(std::string current_visit_time);
            Doctor getDoctor();
            void setDoctor(Doctor doctor);
            std::string getMedicineInformation();
            void setMedicineInformation(std::string medicine_information);

        private:
            std::string first_name_;
            std::string last_name_;
            int age_;
            char gender_;
            std::string contact_number_;
            std::string address_;
            std::string sickness_;
            std::string description_;
            std::string current_visit_date_;
            std::string current_visit_time_;
            std::string disability_;
            Doctor doctor_;
            std::string medicine_information_;
    };
} // namespace pms

#endif // PMS_PATIENT_H
