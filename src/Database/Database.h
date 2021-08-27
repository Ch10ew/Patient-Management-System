#ifndef PMS_DATABASE_H
#define PMS_DATABASE_H

#include "DatabaseInstance.h"

namespace pms
{
    class Database
    {
        public:
            Database();
            void Connect();
            void Query();
            bool IsConnected();

        private:
            DatabaseInstance database_instance_;

    };
} // namespace pms

#endif // PMS_DATABASE_H
