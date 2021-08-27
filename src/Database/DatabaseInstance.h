#ifndef PMS_DATABASEINSTANCE_H
#define PMS_DATABASEINSTANCE_H

#include <string>

namespace pms
{
    /**
     * @brief Defines a row of data for `Patient` that will be communicated between the application and the database.
     */
    struct PATIENT_T
    {
        std::string id;
        std::string first_name;
        std::string last_name;
        int age;
        std::string gender;
        std::string phone;
        std::string address;
        std::string sickness_description;
        std::string current_visit_date;
        std::string current_visit_time;
        std::string disability_option;
        std::string doctor_name;
        std::string medicine_information;
    };

    /**
     * @brief Defines a row of data for `Nurse` that will be communicated between the application and the database.
     */
    struct NURSE_T
    {
        std::string id;
        std::string username;
        std::string first_name;
        std::string last_name;
        std::string password;
    };

    /**
     * @brief Defines a row of data for `Doctor` that will be communicated between the application and the database.
     */
    struct DOCTOR_T
    {
        std::string id;
        std::string username;
        std::string first_name;
        std::string last_name;
        std::string password;
    };

    /**
     * @brief Class that attempts to emulate a DBMS Instance.
     */
    class DatabaseInstance
    {
        public:
            /**
             * @brief Initializes a new Database Instance object with predefined data.
             */
            DatabaseInstance();

            /**
             * @brief Handles a database query string.
             */
            void Query(std::string query);
        
        private:
            PATIENT_T patient_data_;

    };
} // namespace pms

#endif // PMS_DATABASEINSTANCE_H
