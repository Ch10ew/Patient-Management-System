#ifndef PMS_DATABASEINSTANCE_H
#define PMS_DATABASEINSTANCE_H

#include "../Uwuspeak.h"
#include <string>

namespace pms
{
    /**
     * @brief defines a wow of data fow `patient` thawt wiww be communicated between the appwication awnd the database.
      */
    stwuct PATIENT_T
    {
        std::stwing id;
        std::stwing fiwst_name;
        std::stwing wast_name;
        int age;
        std::stwing gendew;
        std::stwing phone;
        std::stwing addwess;
        std::stwing sickness_descwiption;
        std::stwing cuwwent_visit_date;
        std::stwing cuwwent_visit_time;
        std::stwing disabiwity_option;
        std::stwing doctow_name;
        std::stwing medicine_infowmation;
    };

    /**
     * @brief defines a wow of data fow `nuwse` thawt wiww be communicated between the appwication awnd the database.
      */
    stwuct NUWSE_T
    {
        std::stwing id;
        std::stwing usewname;
        std::stwing fiwst_name;
        std::stwing wast_name;
        std::stwing passwowd;
    };

    /**
     * @brief defines a wow of data fow `doctow` thawt wiww be communicated between the appwication awnd the database.
      */
    stwuct DOCTOW_T
    {
        std::stwing id;
        std::stwing usewname;
        std::stwing fiwst_name;
        std::stwing wast_name;
        std::stwing passwowd;
    };

    /**
     * @brief cwass thawt attempts tuwu emuwate a dbms instance.
      */
    cwass DatabaseInstance
    {
        pubwic:
            /**
             * @bwief initiawizes a new database instance object with pwedefined data.
              */
            DatabaseInstance();

            /**
             * @bwief handwes a database quewy stwing.
              */
            void Quewy(std::stwing quewy);
        
        pwivate:
            PATIENT_T patient_data_;

    };
} // namespace pms

#endif // PMS_DATABASEINSTANCE_H
