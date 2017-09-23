//
// Created by Matthew Remmel on 9/18/17.
//

#include "Logger.hpp"
#include <TerminalUtil.hpp>
#include <cstdio>
#include <ctime>
#include <thread>
#include <cstdlib>

using namespace abraham;


std::shared_ptr<Logger> Logger::_sharedInstance = nullptr;

std::shared_ptr<Logger> Logger::sharedInstance() {
    if (_sharedInstance == nullptr) {
        _sharedInstance = std::make_shared<Logger>();
    }

    return _sharedInstance;
}

void Logger::setSharedInstance(const std::shared_ptr<Logger>& logger) {
    _sharedInstance = logger;
}

Logger::Logger(LogLevel level) {
    this->_logLevel = level;
}

void Logger::trace(const String& message, String file, String function, int line) const {
    this->log(LogLevel::trace, message, file, function, line);
}

void Logger::debug(const String& message, String file, String function, int line) const {
    this->log(LogLevel::debug, message, file, function, line);
}

void Logger::info(const String& message, String file, String function, int line) const {
    this->log(LogLevel::info, message, file, function, line);
}

void Logger::notice(const String& message, String file, String function, int line) const {
    this->log(LogLevel::notice, message, file, function, line);
}

void Logger::warning(const String& message, String file, String function, int line) const {
    this->log(LogLevel::warning, message, file, function, line);
}

void Logger::error(const String& message, String file, String function, int line) const {
    this->log(LogLevel::error, message, file, function, line);
}

void Logger::critical(const String& message, String file, String function, int line) const {
    this->log(LogLevel::critical, message, file, function, line);
}

void Logger::alert(const String& message, String file, String function, int line) const {
    this->log(LogLevel::alert, message, file, function, line);
}

void Logger::fatal(const String& message, String file, String function, int line) const {
    this->log(LogLevel::fatal, message, file, function, line);
}

void Logger::log(LogLevel level, const String& message, String file, String function, int line) const {
    if (!(this->shouldWrite(level))) return;

    LogEntry entry;
    entry.file = file;
    entry.function = function;
    entry.line = line;
    entry.logLevel = level;
    entry.timestamp = time(nullptr);

    // Date/Time String
    struct tm tm = {0};
    tm = *std::localtime(&entry.timestamp);
    char date_str[25];
    strftime(date_str, 25, "%F %T %Z", &tm);
    entry.timeString = std::string(date_str);

    entry.message = message;
    this->write(entry);
}

bool Logger::shouldWrite(LogLevel level) const {
    return this->_logLevel <= level;
}

String Logger::getLogMessage(const LogEntry& entry) const {
    return String(entry.timeString + " [" + stringForLogLevel(entry.logLevel) + "] " + entry.message);
}

void Logger::write(const LogEntry& entry) const {
    String message = this->getLogMessage(entry);

    switch (entry.logLevel) {
        case LogLevel::trace:
            TerminalUtil::setTextColor(TTextColor::BLACK);
            TerminalUtil::setBackgroundColor(TBackgroundColor::GREY);
            break;
        case LogLevel::warning:
            TerminalUtil::setTextColor(TTextColor::YELLOW);
            TerminalUtil::setBackgroundColor(TBackgroundColor::BLACK);
            break;
        case LogLevel::error:
            TerminalUtil::setTextColor(TTextColor::RED);
            TerminalUtil::setBackgroundColor(TBackgroundColor::BLACK);
            break;
        case LogLevel::critical:
        case LogLevel::alert:
        case LogLevel::fatal:
            TerminalUtil::setTextColor(TTextColor::BLACK);
            TerminalUtil::setBackgroundColor(TBackgroundColor::RED);
            break;
    }

    printf("%s", message.c_string());
    TerminalUtil::resetColors();
    printf("\n"); // This is on a separate line because the new line was causing background color to jog between lines.
}

LogLevel Logger::getLogLevel() const {
    return this->_logLevel;
}

bool Logger::allEnabled() const {
    return this->_logLevel <= LogLevel::all;
}

bool Logger::traceEnabled() const {
    return this->_logLevel <= LogLevel::trace;
}

bool Logger::debugEnabled() const {
    return this->_logLevel <= LogLevel::debug;
}

bool Logger::infoEnabled() const {
    return this->_logLevel <= LogLevel::info;
}

bool Logger::noticeEnabled() const {
    return this->_logLevel <= LogLevel::notice;
}

bool Logger::warningEnabled() const {
    return this->_logLevel <= LogLevel::warning;
}

bool Logger::errorEnabled() const {
    return this->_logLevel <= LogLevel::error;
}

bool Logger::criticalEnabled() const {
    return this->_logLevel <= LogLevel::critical;
}

bool Logger::alertEnabled() const {
    return this->_logLevel <= LogLevel::alert;
}

bool Logger::fatalEnabled() const {
    return this->_logLevel <= LogLevel::fatal;
}

bool Logger::isOff() const {
    return this->_logLevel <= LogLevel::off;
}

void Logger::setLogLevel(LogLevel level) {
    this->_logLevel = level;
}

String Logger::stringForLogLevel(LogLevel level) const {
    switch (level) {
        case LogLevel::all:
            return "ALL";

        case LogLevel::trace:
            return "TRACE";

        case LogLevel::debug:
            return "DEBUG";

        case LogLevel::info:
            return "INFO";

        case LogLevel::notice:
            return "NOTICE";

        case LogLevel::warning:
            return "WARNING";

        case LogLevel::error:
            return "ERROR";

        case LogLevel::critical:
            return "CRITICAL";

        case LogLevel::alert:
            return "ALERT";

        case LogLevel::fatal:
            return "FATAL";

        case LogLevel::off:
            return "OFF";
    }
}
