#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#ifdef _WIN32
#include <windows.h>
#endif // _WIN32

#include <iostream>
#include <sstream>
#include <string>

namespace console
{
    enum class CONSOLE
    {
        WIDTH = 104,
        HEIGHT = 30,
    };

    enum class ANSI_SEQ
    {
        ESC_CURSOR_SHOW,
        ESC_CURSOR_HIDE,
        ESC_CURSOR_UP,
        ESC_CURSOR_UP_256,
        ESC_CURSOR_DOWN,
        ESC_CURSOR_DOWN_256,
        ESC_CURSOR_RIGHT,
        ESC_CURSOR_RIGHT_256,
        ESC_CURSOR_LEFT,
        ESC_CURSOR_LEFT_256,
        ESC_CLEAR_SCREEN,
        ESC_MODE_RESET,
        ESC_MODE_BOLD,
        ESC_MODE_UNDERLINE,
        ESC_MODE_F_BLACK,
        ESC_MODE_F_RED,
        ESC_MODE_F_GREEN,
        ESC_MODE_F_YELLOW,
        ESC_MODE_F_BLUE,
        ESC_MODE_F_MAGENTA,
        ESC_MODE_F_CYAN,
        ESC_MODE_F_WHITE,
        ESC_MODE_B_BLACK,
        ESC_MODE_B_RED,
        ESC_MODE_B_GREEN,
        ESC_MODE_B_YELLOW,
        ESC_MODE_B_BLUE,
        ESC_MODE_B_MAGENTA,
        ESC_MODE_B_CYAN,
        ESC_MODE_B_WHITE,
        ESC_DEC_BOTTOM_RIGHT_CORNER,
        ESC_DEC_TOP_RIGHT_CORNER,
        ESC_DEC_TOP_LEFT_CORNER,
        ESC_DEC_BOTTOM_LEFT_CORNER,
        ESC_DEC_JUNCTION,
        ESC_DEC_HORIZONTAL,
        ESC_DEC_MIDDLE_LEFT,
        ESC_DEC_MIDDLE_RIGHT,
        ESC_DEC_BOTTOM_MIDDLE,
        ESC_DEC_TOP_MIDDLE,
        ESC_DEC_VERTICAL,
        ESC_COUNT,
    };

    /**
     * @brief Moves the cursor to position `x`, `y`.
     * 
     * @param x New x pos
     * @param y New y pos
     * @return std::string String to print to console to move the cursor.
     */
    static inline std::string AnsiEscCursorPosition(int x, int y)
    {
        std::stringstream ss;
        ss << "\x1b[" << ++y << ";" << ++x << "H";
        return ss.str();
    }

    /**
     * @brief Converts an `ANSI_SEQ` enum to its string counterpart.
     * 
     * @param e `ANSI_SEQ` enum
     * @return std::string String to print to console to achieve the effect.
     */
    static std::string AnsiEsc(ANSI_SEQ e)
    {
        switch (e)
        {
            case ANSI_SEQ::ESC_CURSOR_SHOW:
                return "\x1b[?25h";
                break;
            case ANSI_SEQ::ESC_CURSOR_HIDE:
                return "\x1b[?25l";
                break;
            case ANSI_SEQ::ESC_CURSOR_UP:
                return "\x1b[A";
                break;
            case ANSI_SEQ::ESC_CURSOR_UP_256:
                return "\x1b[256A";
                break;
            case ANSI_SEQ::ESC_CURSOR_DOWN:
                return "\x1b[B";
                break;
            case ANSI_SEQ::ESC_CURSOR_DOWN_256:
                return "\x1b[256B";
                break;
            case ANSI_SEQ::ESC_CURSOR_RIGHT:
                return "\x1b[C";
                break;
            case ANSI_SEQ::ESC_CURSOR_RIGHT_256:
                return "\x1b[256C";
                break;
            case ANSI_SEQ::ESC_CURSOR_LEFT:
                return "\x1b[D";
                break;
            case ANSI_SEQ::ESC_CURSOR_LEFT_256:
                return "\x1b[256D";
                break;
            case ANSI_SEQ::ESC_CLEAR_SCREEN:
                return "\x1b[256S\x1b[H\x1b[2J";  // Scroll viewport up by 256; Reset position to 0,0; Clear screen
                break;
            case ANSI_SEQ::ESC_MODE_RESET:
                return "\x1b[0m";
                break;
            case ANSI_SEQ::ESC_MODE_BOLD:
                return "\x1b[1m";
                break;
            case ANSI_SEQ::ESC_MODE_UNDERLINE:
                return "\x1b[4m";
                break;
            case ANSI_SEQ::ESC_MODE_F_BLACK:
                return "\x1b[30m";
                break;
            case ANSI_SEQ::ESC_MODE_F_RED:
                return "\x1b[31m";
                break;
            case ANSI_SEQ::ESC_MODE_F_GREEN:
                return "\x1b[32m";
                break;
            case ANSI_SEQ::ESC_MODE_F_YELLOW:
                return "\x1b[33m";
                break;
            case ANSI_SEQ::ESC_MODE_F_BLUE:
                return "\x1b[34m";
                break;
            case ANSI_SEQ::ESC_MODE_F_MAGENTA:
                return "\x1b[35m";
                break;
            case ANSI_SEQ::ESC_MODE_F_CYAN:
                return "\x1b[36m";
                break;
            case ANSI_SEQ::ESC_MODE_F_WHITE:
                return "\x1b[37m";
                break;
            case ANSI_SEQ::ESC_MODE_B_BLACK:
                return "\x1b[40m";
                break;
            case ANSI_SEQ::ESC_MODE_B_RED:
                return "\x1b[41m";
                break;
            case ANSI_SEQ::ESC_MODE_B_GREEN:
                return "\x1b[42m";
                break;
            case ANSI_SEQ::ESC_MODE_B_YELLOW:
                return "\x1b[43m";
                break;
            case ANSI_SEQ::ESC_MODE_B_BLUE:
                return "\x1b[44m";
                break;
            case ANSI_SEQ::ESC_MODE_B_MAGENTA:
                return "\x1b[45m";
                break;
            case ANSI_SEQ::ESC_MODE_B_CYAN:
                return "\x1b[46m";
                break;
            case ANSI_SEQ::ESC_MODE_B_WHITE:
                return "\x1b[47m";
                break;
            case ANSI_SEQ::ESC_DEC_BOTTOM_RIGHT_CORNER:
                return "\x1b(0j\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_TOP_RIGHT_CORNER:
                return "\x1b(0k\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_TOP_LEFT_CORNER:
                return "\x1b(0l\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_BOTTOM_LEFT_CORNER:
                return "\x1b(0m\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_JUNCTION:
                return "\x1b(0n\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_HORIZONTAL:
                return "\x1b(0q\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_MIDDLE_LEFT:
                return "\x1b(0t\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_MIDDLE_RIGHT:
                return "\x1b(0u\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_BOTTOM_MIDDLE:
                return "\x1b(0v\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_TOP_MIDDLE:
                return "\x1b(0w\x1b(B";
                break;
            case ANSI_SEQ::ESC_DEC_VERTICAL:
                return "\x1b(0x\x1b(B";
                break;
            case ANSI_SEQ::ESC_COUNT:
            default:
                return "";
                break;
        }
    }

    /**
     * @brief Sets up the console/terminal to support ANSI Escape sequences.
     * 
     */
    static void InitConsole()
    {
        #ifdef _WIN32
            // WINAPI Setup for Terminal (Windows only)
            // https://docs.microsoft.com/en-us/windows/console/getstdhandle
            // GetStdHandle(-10) - Get stdin
            // GetStdHandle(-11) - Get stdout
            // https://docs.microsoft.com/en-us/windows/console/setconsolemode
            // For stdin,
            //   0x0200 - ENABLE_VIRTUAL_TERMINAL_INPUT
            // For stdout,
            //   0x0004 - ENABLE_VIRTUAL_TERMINAL_PROCESSING
            DWORD original_mode = 0;
            /*HANDLE stdin_handle = GetStdHandle(-10);*/
            HANDLE stdout_handle = GetStdHandle(-11);
            // stdin
            /*GetConsoleMode(stdin_handle, &original_mode);
            SetConsoleMode(stdin_handle, original_mode | 0x0200);*/

            // stdout
            GetConsoleMode(stdout_handle, &original_mode);
            SetConsoleMode(stdout_handle, original_mode | 0x0004);
        #else
            // termios Setup for Terminal (Linux only)
            // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/termios.h.html
            /*struct termios t;
            tcgetattr(STDIN_FILENO, &t);
            t.c_lflag &= ~ICANON; // Canonical input
            tcsetattr(STDIN_FILENO, TSCANOW, &t);*/
        #endif // _WIN32
    }
} // namespace console

#endif // UI_CONSOLE_H
