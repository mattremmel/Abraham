//
// Created by Matthew Remmel on 9/18/17.
//

#ifndef ABRAHAM_LOGGER_HPP
#define ABRAHAM_LOGGER_HPP

#include "String.hpp"
#include "SharedPtr.hpp"


/*
 * Macros used by the Core Logger
 */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#ifdef __PRETTY_FUNCTION__
#define __FUNC_NAME__ __PRETTY_FUNCTION__
#else
#define __FUNC_NAME__ __func__
#endif

/*
 * Macros for verbose log messages
 */
#define log_trace(message)      abraham::Logger::sharedInstance()->trace(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_debug(message)      abraham::Logger::sharedInstance()->debug(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_info(message)       abraham::Logger::sharedInstance()->info(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_notice(message)     abraham::Logger::sharedInstance()->notice(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_warning(message)    abraham::Logger::sharedInstance()->warning(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_error(message)      abraham::Logger::sharedInstance()->error(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_critical(message)   abraham::Logger::sharedInstance()->critical(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_alert(message)      abraham::Logger::sharedInstance()->alert(message, __FILENAME__, __FUNC_NAME__, __LINE__)
#define log_fatal(message)      abraham::Logger::sharedInstance()->fatal(message, __FILENAME__, __FUNC_NAME__, __LINE__)

namespace abraham {

    /**
     * The different possible log levels supported.
     */
    enum class LogLevel {
        ALL = 0,
        TRACE = 10,
        DEBUG = 20,
        INFO = 30,
        NOTICE = 40,
        WARNING = 50,
        ERROR = 60,
        CRITICAL = 70,
        ALERT = 80,
        FATAL = 90,
        OFF = 100
    };

    /**
     * All the information needed to represent a log entry.
     */
    struct LogEntry {
        /**
         * The source file that the log originated from.
         */
        String file;

        /**
         * The function name that the log originated from.
         */
        String function;

        /**
         * The line number that the log originated from.
         */
        int line;

        /**
         * The LogLevel of the log message.
         */
        LogLevel logLevel;

        /**
         * The time that the message was logged.
         */
        time_t timestamp;

        /**
         * The date/time string representation
         */
        String timeString;

        /**
         * The message of the log message.
         */
        String message;
    };


    /**
     * A standard logging class that writes to stdout, and is the base class for other logging implementations.
     *
     * Macros are provided for normal and convenient use, as well as automatically including the file, function, and
     * line number of the log message:
     *
     * - log_trace(message);
     * - log_debug(message);
     * - log_info(message);
     * - log_notice(message);
     * - log_warning(message);
     * - log_error(message);
     * - log_critical(message);
     * - log_alert(message);
     * - log_fatal(message);
     */
    class Logger {
    protected:
        /**
         * The shared logging instance used with the "log_[level]" macros.
         */
        static SharedPtr<Logger> _sharedInstance;

        /**
         * The current log level of this logger.
         */
        LogLevel _logLevel;

    public:
        /**
         * The shared Logger instance which is of type Logger by default, but can be set to any other subclass using setSharedInstance().
         * @return The shared Logger instance.
         */
        static SharedPtr<Logger> sharedInstance();

        /**
         * Set a new shared logging instance.
         * @param sharedInstance - Either a Logger or Logger subclass shared instance.
         */
        static void setSharedInstance(const SharedPtr<Logger>& sharedInstance);

        /**
         * Default constructor that creates a standard Logger with log level set to 'all' by default.
         * @param level = The log level this Logger should be initialized to.
         */
        explicit Logger(LogLevel level = LogLevel::ALL);

        /**
         * Log a message with level 'trace'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_trace" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_trace' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_trace' macro.
         */
        void trace(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'debug'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_debug" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_debug' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_debug' macro.
         */
        void debug(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'info'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_info" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_info' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_info' macro.
         */
        void info(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'notice'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_notice" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_notice' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_notice' macro.
         */
        void notice(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'warning'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_warning" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_warning' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_warning' macro.
         */
        void warning(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'error'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_error" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_error' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_error' macro.
         */
        void error(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'critical'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_critical" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_critical' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_critical' macro.
         */
        void critical(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'alert'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_alert" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_alert' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_alert' macro.
         */
        void alert(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Log a message with level 'fatal'.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_fatal" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_fatal' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_fatal' macro.
         */
        void fatal(const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Generic function to log a message. Intended to be used only by other log functions.
         * @param level - The log level of the message.
         * @param message - The message to be logged.
         * @param file - The file the log message originated from. Intended to be used only by 'log_[level]" macro.
         * @param function - The function the log message originated from. Intended to be used only by 'log_[level]' macro.
         * @param line - The line number the log message originated from. Intended to be used only by the 'log_[level]' macro.
         */
        void log(LogLevel level, const String& message, const String& file = "", const String& function = "", int line = 0) const;

        /**
         * Determines if a log message of the provided level should be written.
         * Can be overridden for implementing specialized behavior; see MultiLogger.
         * @param level - The log level of the message.
         * @return true if the message should be logged; false otherwise.
         */
        virtual bool shouldWrite(LogLevel level) const;

        /**
         * Returns the constructed String log message from the provided LogEntry.
         * Can be overriden for changing the message format of a most Logger types.
         * @param entry - The LogEntry representation of the log message.
         * @return The constructed String log message from the LogEntry.
         */
        virtual String getLogMessage(const LogEntry& entry) const;

        /**
         * The function that writes the LogEntry object to the Logger specific output.
         * @param entry - The LogEntry representation of the log message.
         */
        virtual void write(const LogEntry& entry) const;

        /**
         * @return The current log level of the Logger.
         */
        LogLevel getLogLevel() const;

        /**
         * @return true if all logging levels are enabled; false otherwise.
         */
        bool allEnabled() const;

        /**
         * @return true if the trace logging level is enabled; false otherwise.
         */
        bool traceEnabled() const;

        /**
         * @return true if the debug logging level is enabled; false otherwise.
         */
        bool debugEnabled() const;

        /**
         * @return true if the info logging level is enabled; false otherwise.
         */
        bool infoEnabled() const;

        /**
         * @return true if the notice logging level is enabled; false otherwise.
         */
        bool noticeEnabled() const;

        /**
         * @return true if the warning logging level is enabled; false otherwise.
         */
        bool warningEnabled() const;

        /**
         * @return true if the error logging level is enabled; false otherwise.
         */
        bool errorEnabled() const;

        /**
         * @return true if the critical logging level is enabled; false otherwise.
         */
        bool criticalEnabled() const;

        /**
         * @return true if the alert logging level is enabled; false otherwise.
         */
        bool alertEnabled() const;

        /**
         * @return true if the fatal logging level is enabled; false otherwise.
         */
        bool fatalEnabled() const;

        /**
         * @return true if all logging levels are disabled; false otherwise.
         */
        bool isOff() const;

        /**
         * Sets a new logging level for the Logger.
         * @param level - The new log level to set.
         */
        virtual void setLogLevel(LogLevel level);

        /**
         * Returns the String representation of the specified log level.
         * @param level - The log level to get String of.
         * @return A String representation of the specified log level.
         */
        String stringForLogLevel(LogLevel level) const;

        /**
         * Virtual default destructor to allow shared instances of any subclasses to release resources correctly.
         */
        virtual ~Logger() = default;
    };
}

#endif //ABRAHAM_LOGGER_HPP
