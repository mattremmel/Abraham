//
// Created by Matthew Remmel on 9/19/17.
//

#ifndef ABRAHAM_TERMINALUTIL_HPP
#define ABRAHAM_TERMINALUTIL_HPP

#include "String.hpp"


namespace abraham {

    /**
     * Enum of text colors that can be set for terminal output.
     */
    enum class TTextColor {
        BLACK = 0,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY,
        DARKGREY,
        LIGHTBLUE,
        LIGHTGREEN,
        LIGHTCYAN,
        LIGHTRED,
        LIGHTMAGENTA,
        YELLOW,
        WHITE
    };

    /**
     * Enum of background colors that can be set for terminal output.
     */
    enum class TBackgroundColor {
        BLACK = 0,
        BLUE,
        GREEN,
        CYAN,
        RED,
        MAGENTA,
        BROWN,
        GREY
    };

    /**
     * Key codes for the non-alphanumeric characters and input.
     */
    enum class KeyCode {
        KEY_ESCAPE  = 0,
        KEY_ENTER   = 1,
        KEY_SPACE   = 32,

        KEY_INSERT  = 2,
        KEY_HOME    = 3,
        KEY_PGUP    = 4,
        KEY_DELETE  = 5,
        KEY_END     = 6,
        KEY_PGDOWN  = 7,

        KEY_UP      = 14,
        KEY_DOWN    = 15,
        KEY_LEFT    = 16,
        KEY_RIGHT   = 17,

        KEY_F1      = 18,
        KEY_F2      = 19,
        KEY_F3      = 20,
        KEY_F4      = 21,
        KEY_F5      = 22,
        KEY_F6      = 23,
        KEY_F7      = 24,
        KEY_F8      = 25,
        KEY_F9      = 26,
        KEY_F10     = 27,
        KEY_F11     = 28,
        KEY_F12     = 29,

        KEY_NUMDEL  = 30,
        KEY_NUMPAD0 = 31,
        KEY_NUMPAD1 = 127,
        KEY_NUMPAD2 = 128,
        KEY_NUMPAD3 = 129,
        KEY_NUMPAD4 = 130,
        KEY_NUMPAD5 = 131,
        KEY_NUMPAD6 = 132,
        KEY_NUMPAD7 = 133,
        KEY_NUMPAD8 = 134,
        KEY_NUMPAD9 = 135,
    };

    /**
     * Utility functions for interacting with a terminal or console.
     */
    class TerminalUtil {
    public:
        /**
         * Blocking function that returns the next key that was pressed.
         * @return The character key that was pressed.
         */
        static char getKey();

        /**
         * @return true if a key was pressed and can be retrieved; false otherwise.
         */
        static bool keyWasPressed();

        /**
         * Blocking function that waits for any key to be pressed.
         */
        static void waitForAnyKey();

        /**
         * Sets the text color attribute when written to the screen. The color will persist until reset.
         * @param color - The color to print the text in.
         */
        static void setTextColor(TTextColor color);

        /**
         * Sets the background color attribute of the text when written to the screen. The color will persist until reset.
         * @param color - The color to print the text background in.
         */
        static void setBackgroundColor(TBackgroundColor color);

        /**
         * Resets the text and terminal color attributes back to their defaults.
         */
        static void resetColors();

        /**
         * Clears the terminal screen and resets the cursor and any attributes.
         */
        static void clearScreen();

        /**
         * Prints the String at the current location without advancing the cursor.
         * @param string - The String to print to the screen.
         */
        static void setString(const String& string);

        /**
         * Sets the cursor to the specified 1-base position. 1,1 is the top left of the terminal.
         * @param x - The horizontal 1-based x-position of the cursor.
         * @param y - The vertical 1-based y-position of the cursor.
         */
        static void setCursor(int x, int y);

        /**
         * Shows the cursor in the terminal.
         */
        static void showCursor();

        /**
         * Hides the cursor in the terminal.
         */
        static void hideCursor();

        /**
         * @return The height of the terminal in terms of the number of rows.
         */
        static int rowCount();

        /**
         * @return The width of the terminal in terms of the number of columns.
         */
        static int columnCount();
    };

    /**
     * RAII wrapper for the show/hide cursor functions that will automatically hide the cursor, and then show it when the object goes out of scope.
     */
    struct CursorHider {
        CursorHider() { TerminalUtil::hideCursor(); };
        ~CursorHider() { TerminalUtil::showCursor(); };
    };
}

#endif //ABRAHAM_TERMINALUTIL_HPP
