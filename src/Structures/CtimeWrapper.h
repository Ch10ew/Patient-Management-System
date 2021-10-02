#ifndef CTIME_WRAPPER
#define CTIME_WRAPPER

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdio.h>

namespace ctimew
{
    /**
     * @brief Gets the current time, in POSIX time (`long long`).
     * 
     * @return time_t Current time in POSIX format.
     */
    static time_t Time()
    {
        time_t currentTime;
        return time(&currentTime);
    }
    
    /**
     * @brief Gets local time in `struct tm`
     * 
     * @return tm* Local time in `struct tm` pointer
     */
    static tm* StructTM(time_t time)
    {
        return localtime(&time); 
    }

    /**
     * @brief Convert struct tm to a string of readable time.
     * 
     * @param struct tm* Pointer
     * @return std::string String of readable time
     */
    static std::string FormatTime(tm* data)
    {
        std::string s = asctime(data);
        s.pop_back();
        return s;
    }

    /**
     * @brief Get date in the format of "DD/MM/YYYY" from `struct tm`.
     * 
     * @param struct tm* Pointer
     * @return std::string Date in the format of "DD/MM/YYYY"
     */
    static std::string GetDate(tm *data)
    {
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

    /**
     * @brief Get time in the format of "HH:MM:SS" from `struct tm`.
     * 
     * @param struct tm* Pointer
     * @return std::string Time in the format of "HH:MM:SS"
     */
    static std::string GetTime(tm *data)
    {
        std::stringstream ss;
        ss << std::setfill('0');
        ss << std::setw(2) << data->tm_hour << ':'
        << std::setw(2) << data->tm_min << ':'
        << std::setw(2) << data->tm_sec;
        return ss.str();
    }

    /**
     * @brief Attempts to parse `std::string` to `time_t`.
     * 
     * Throws `std::invalid_argument` if argument is invalid.
     * 
     * Will return broken `time_t` (`time_t` with -1 as value) if given invalid arguments.
     * 
     * @param data 
     * @return time_t 
     */
    static time_t GetTimeTFromString(std::string data)
    {
        // Parse string using sscanf
        const char* char_arr_ptr = data.c_str();
        int year, month, day, hour, minute, second;
        int res = sscanf(char_arr_ptr, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

        if (res != 6)
            throw std::invalid_argument("ctimew::GetTimeTFromString(): String parsing failed");
        
        // Find time from epoch
        struct tm tm_tmp;
        tm_tmp.tm_year = year - 1900;
        tm_tmp.tm_mon = month - 1;
        tm_tmp.tm_mday = day;
        tm_tmp.tm_hour = hour;
        tm_tmp.tm_min = minute;
        tm_tmp.tm_sec = second;
        tm_tmp.tm_isdst = -1;

        // get time_t
        time_t time_tmp = mktime(&tm_tmp);

        return time_tmp;
    }
} // namespace ctimew

#endif // CTIME_WRAPPER