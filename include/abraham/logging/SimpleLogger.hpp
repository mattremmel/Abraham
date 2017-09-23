//
// Created by Matthew Remmel on 9/19/17.
//

#ifndef ABRAHAM_SIMPLELOGGER_HPP
#define ABRAHAM_SIMPLELOGGER_HPP

#include "Logger.hpp"


namespace abraham {

    /**
     * A subclass of Logger that only writes the log level and the message to the console.
     */
    class SimpleLogger : public Logger {
    public:
        /**
         * Default constructor that creates a SimpleLogger with log level 'all' by default.
         * @param level - The log level to initialize the SimpleLogger to.
         */
        explicit SimpleLogger(LogLevel level = LogLevel::all);

        /**
         * An override to only include the log level and message in the log message.
         */
        String getLogMessage(const LogEntry& entry) const override;
    };
}

#endif //ABRAHAM_SIMPLELOGGER_HPP
