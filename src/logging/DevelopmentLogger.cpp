//
// Created by Matthew Remmel on 9/20/17.
//

#include "DevelopmentLogger.hpp"

using namespace abraham;


DevelopmentLogger::DevelopmentLogger(LogLevel level) {
    this->_logLevel = level;
}

String DevelopmentLogger::getLogMessage(const LogEntry& entry) const {
    return String(entry.timeString + " " + entry.file + ":" + std::to_string(entry.line) + " " + entry.function + " [" + stringForLogLevel(entry.logLevel) + "] " + entry.message);
}
