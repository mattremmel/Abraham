//
// Created by Matthew Remmel on 9/19/17.
//

#include "TerminalUtil.hpp"
#include "rlutil.hpp"

using namespace abraham;


char TerminalUtil::getKey() {
    return (char)rlutil::getkey();
}

bool TerminalUtil::keyWasPressed() {
    return (bool)kbhit();
}

void TerminalUtil::waitForAnyKey() {
    rlutil::anykey();
}

void TerminalUtil::setTextColor(TTextColor color) {
    rlutil::setColor((int)color);
}

void TerminalUtil::setBackgroundColor(TBackgroundColor color) {
    rlutil::setBackgroundColor((int)color);
}

void TerminalUtil::resetColors() {
    rlutil::resetColor();
}

void TerminalUtil::clearScreen() {
    rlutil::cls();
}

void TerminalUtil::setString(const String& string) {
    rlutil::setString(string.std_string());
}

void TerminalUtil::setCursor(int x, int y) {
    rlutil::locate(x, y);
}

void TerminalUtil::showCursor() {
    rlutil::showcursor();
}

void TerminalUtil::hideCursor() {
    rlutil::hidecursor();
}

int TerminalUtil::rowCount() {
    return rlutil::trows();
}

int TerminalUtil::columnCount() {
    return rlutil::tcols();
}
