//
// Created by Matthew Remmel on 9/19/17.
//

#include "MultiLogger.hpp"
#include <Exception.hpp>

using namespace abraham;


MultiLogger::MultiLogger() {
    this->_logLevel = LogLevel::ALL;
    this->_loggers = std::vector<MultiLoggerEntry>();
}

void MultiLogger::addLogger(const String& name, const std::shared_ptr<Logger>& logger) {
    this->_loggers.push_back({name, logger});
}

bool MultiLogger::hasLogger(const String& name) const {
    for (auto l : this->_loggers) {
        if (l.name == name) {
            return true;
        }
    }

    return false;
}

std::shared_ptr<Logger> MultiLogger::getLogger(const String& name) {
    for (auto l: this->_loggers) {
        if (l.name == name) {
            return l.logger;
        }
    }

    throw InvalidArgumentException("Logger with name: " + name.std_string() + " doesn't exist");
}

void MultiLogger::removeLogger(const String& name) {
    for (int i = 0; i < this->_loggers.size(); ++i) {
        if (this->_loggers[i].name == name) {
            this->_loggers.erase(this->_loggers.begin() + i);
        }
    }

    throw InvalidArgumentException("Logger with name: " + name.std_string() + " doesn't exist");
}

void MultiLogger::setLogLevel(LogLevel level) {
    for (auto l : this->_loggers) {
        l.logger->setLogLevel(level);
    }
}

void MultiLogger::setLogLevel(const String& name, LogLevel level) {
    for (auto l : this->_loggers) {
        if (l.name == name) {
            l.logger->setLogLevel(level);
        }
    }

    throw InvalidArgumentException("Logger with name: " + name.std_string() + " doesn't exist");
}

bool MultiLogger::shouldWrite(LogLevel level) const {
    return true;
}

void MultiLogger::write(const LogEntry& entry) const {
    for (auto l : this->_loggers) {
        if (l.logger->shouldWrite(entry.logLevel)) {
            l.logger->write(entry);
        }
    }
}
