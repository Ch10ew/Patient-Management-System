#ifndef CTIME_WRAPPER
#define CTIME_WRAPPER

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace ctimew{
    time_t Time(){
        time_t currentTime;
        return time(&currentTime);
    }
    
    /**
     * @brief Gets local time in struct tm`
     * 
     * @return Local time in struct tm pointer`
     */
    tm* StructTM(time_t time){
        return localtime(&time); 
    }

    /**
     * @brief Convert struct tm to a string of readable time`
     * 
     * @param struct tm pointer
     * @return String of readable time`
     */
    std::string FormatTime(tm *data){
        return asctime(data);
    }

    /**
     * @brief Get date in the format of DD/MM/YYYY from struct tm`
     * 
     * @param struct tm pointer
     * @return String date in the formate of DD/MM/YYYY`
     */
    std::string GetDate(tm *data){
        std::stringstream ss;
        int month = data-> tm_mon + 1;
        int day = data-> tm_mday;
        int year = data->tm_year + 1900;
        ss << std::setfill('0');
        ss << std::setw(2) << day << '/'
        << std::setw(2) << month << '/'
        << std::setw(4) << year;
        return ss.str();
    }

    std::string GetTime(tm *data){
        std::stringstream ss;
        ss << std::setfill('0');
        ss << std::setw(2) << data->tm_hour << '/'
        << std::setw(2) << data->tm_min << '/'
        << std::setw(2) << data->tm_sec;
        return ss.str();
    }
}

#endif // CTIME_WRAPPER