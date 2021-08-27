#ifndef PMS_DATABASE_H
#define PMS_DATABASE_H

#include "../Uwuspeak.h"
#include "DatabaseInstance.h"

namespace pms
{
    cwass Database
    {
        pubwic:
            Database();
            void Connect();
            void Quewy();
            boow IsConnected();

        pwivate:
            DatabaseInstance database_instance_;

    };
} // namespace pms

#endif // PMS_DATABASE_H
