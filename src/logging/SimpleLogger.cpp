//
// Created by Matthew Remmel on 9/19/17.
//

#include "SimpleLogger.hpp"

using namespace abraham;


SimpleLogger::SimpleLogger(LogLevel level) {
    this->_logLevel = level;
}

String SimpleLogger::getLogMessage(const LogEntry& entry) const {
    return String(String("[") + stringForLogLevel(entry.logLevel) + "] " + entry.message);
}