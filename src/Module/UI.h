#ifndef PMS_UI_H
#define PMS_UI_H

namespace pms
{
    class UI
    {
        public:
            virtual void Run() = 0;

        protected:
            bool module_name;
    };
} // namespace pms

#endif // PMS_UI_H
