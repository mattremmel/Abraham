//
// Created by Matthew Remmel on 9/19/17.
//

#ifndef ABRAHAM_MULTILOGGER_HPP
#define ABRAHAM_MULTILOGGER_HPP

#include "Logger.hpp"
#include "String.hpp"
#include <vector>


namespace abraham {

    /**
     * A subclass of a Logger that allows sending log message to multiple loggers, such as console,
     * file, network, and or database, at the same time.
     */
    class MultiLogger : public Logger {
    private:
        /**
         * Struct to internally map a String identifier to a Logger.
         */
        struct MultiLoggerEntry {
            String name;
            std::shared_ptr<Logger> logger;
        };

        /**
         * The internal array of Logger entries.
         */
        std::vector<MultiLoggerEntry> _loggers;

    public:
        /**
         * Default constructor to create an empty MultiLogger.
         */
        MultiLogger();

        /**
         * Add a Logger instance to the MultiLogger.
         * @param name - The unique String identifier for the Logger.
         * @param logger - The Logger instance to add.
         */
        void addLogger(const String& name, const std::shared_ptr<Logger>& logger);

        /**
         * Checks whether a Logger of the provided identifier exists in the MultiLogger.
         * @param name - The identifier of the Logger.
         * @return true if the Logger exists in the MultiLogger; false otherwise.
         */
        bool hasLogger(const String& name) const;

        /**
         * Removes a Logger from the MultiLogger.
         * @param name - The identifier of the Logger to remove.
         */
        void removeLogger(const String& name);

        /**
         * Get the instance of a Logger held by the MultiLogger.
         * @param name - The identifier of the Logger to get.
         * @return The instance of the Logger.
         */
        std::shared_ptr<Logger> getLogger(const String& name);

        /**
         * Set a new log level for all Logger instances in the MultiLogger.
         * @param level - The new log level to set for all instances.
         */
        void setLogLevel(LogLevel level) override;

        /**
         * Set a new log level for a specific Logger in the MultiLogger.
         * @param name - The identifier of the Logger.
         * @param level - The new log level to set for the Logger.
         */
        void setLogLevel(const String& name, LogLevel level);

        /**
         * An override to send all log messages to each Logger in the MultiLogger, regardless of the MultiLoggers log level.
         * @return Always returns true.
         */
        bool shouldWrite(LogLevel level) const override;

        /**
         * An override to forward every LogEntry to each Logger in the MultiLogger.
         */
        void write(const LogEntry& entry) const override;
    };
}

#endif //ABRAHAM_MULTILOGGER_HPP
