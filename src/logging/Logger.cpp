//
// Created by Matthew Remmel on 9/18/17.
//

#include "Logger.hpp"
#include <TerminalUtil.hpp>
#include <ctime>
#include <thread>

using namespace abraham;


SharedPtr<Logger> Logger::_sharedInstance = nullptr;

SharedPtr<Logger> Logger::sharedInstance() {
    if (_sharedInstance == nullptr) {
        _sharedInstance = SharedPtr<Logger>::make();
    }

    return _sharedInstance;
}

void Logger::setSharedInstance(const SharedPtr<Logger>& logger) {
    _sharedInstance = logger;
}

Logger::Logger(LogLevel level) {
    this->_logLevel = level;
}

void Logger::trace(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::TRACE, message, file, function, line);
}

void Logger::debug(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::DEBUG, message, file, function, line);
}

void Logger::info(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::INFO, message, file, function, line);
}

void Logger::notice(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::NOTICE, message, file, function, line);
}

void Logger::warning(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::WARNING, message, file, function, line);
}

void Logger::error(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::ERROR, message, file, function, line);
}

void Logger::critical(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::CRITICAL, message, file, function, line);
}

void Logger::alert(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::ALERT, message, file, function, line);
}

void Logger::fatal(const String& message, const String& file, const String& function, int line) const {
    this->log(LogLevel::FATAL, message, file, function, line);
}

void Logger::log(LogLevel level, const String& message, const String& file, const String& function, int line) const {
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
        case LogLevel::TRACE:
            TerminalUtil::setTextColor(TTextColor::BLACK);
            TerminalUtil::setBackgroundColor(TBackgroundColor::GREY);
            break;
        case LogLevel::WARNING:
            TerminalUtil::setTextColor(TTextColor::YELLOW);
            TerminalUtil::setBackgroundColor(TBackgroundColor::BLACK);
            break;
        case LogLevel::ERROR:
            TerminalUtil::setTextColor(TTextColor::RED);
            TerminalUtil::setBackgroundColor(TBackgroundColor::BLACK);
            break;
        case LogLevel::CRITICAL:
        case LogLevel::ALERT:
        case LogLevel::FATAL:
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
    return this->_logLevel <= LogLevel::ALL;
}

bool Logger::traceEnabled() const {
    return this->_logLevel <= LogLevel::TRACE;
}

bool Logger::debugEnabled() const {
    return this->_logLevel <= LogLevel::DEBUG;
}

bool Logger::infoEnabled() const {
    return this->_logLevel <= LogLevel::INFO;
}

bool Logger::noticeEnabled() const {
    return this->_logLevel <= LogLevel::NOTICE;
}

bool Logger::warningEnabled() const {
    return this->_logLevel <= LogLevel::WARNING;
}

bool Logger::errorEnabled() const {
    return this->_logLevel <= LogLevel::ERROR;
}

bool Logger::criticalEnabled() const {
    return this->_logLevel <= LogLevel::CRITICAL;
}

bool Logger::alertEnabled() const {
    return this->_logLevel <= LogLevel::ALERT;
}

bool Logger::fatalEnabled() const {
    return this->_logLevel <= LogLevel::FATAL;
}

bool Logger::isOff() const {
    return this->_logLevel <= LogLevel::OFF;
}

void Logger::setLogLevel(LogLevel level) {
    this->_logLevel = level;
}

String Logger::stringForLogLevel(LogLevel level) const {
    switch (level) {
        case LogLevel::ALL:
            return "ALL";

        case LogLevel::TRACE:
            return "TRACE";

        case LogLevel::DEBUG:
            return "DEBUG";

        case LogLevel::INFO:
            return "INFO";

        case LogLevel::NOTICE:
            return "NOTICE";

        case LogLevel::WARNING:
            return "WARNING";

        case LogLevel::ERROR:
            return "ERROR";

        case LogLevel::CRITICAL:
            return "CRITICAL";

        case LogLevel::ALERT:
            return "ALERT";

        case LogLevel::FATAL:
            return "FATAL";

        case LogLevel::OFF:
            return "OFF";
    }
}
