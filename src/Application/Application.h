#ifndef PMS_APPLICATION_H
#define PMS_APPLICATION_H

#include "../Structures/List.h"
#include "../Module/UI.h"

namespace pms
{
    class Application
    {
        public:
            Application();

            void Run();

        private:
            pms::List<UI> modules;
            bool exit_;
    };
} // namespace pms

#endif // PMS_APPLICATION_H
