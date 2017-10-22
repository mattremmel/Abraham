//
// Created by Matthew Remmel on 9/20/17.
//

#ifndef ABRAHAM_DEVELOPMENTLOGGER_HPP
#define ABRAHAM_DEVELOPMENTLOGGER_HPP

#include "Logger.hpp"


namespace abraham {

    /**
     * A subclass of Logger that includes the source file, function, and line number of the log message, in addition
     * to the other information in the standard Logger output.
     */
    class DevelopmentLogger : public Logger {
    public:
        /**
         * Default constructor that creates a DevelopmentLogger with the log level set to 'all' by default.
         * @param level - The log level to initialize the DevelopmentLogger to.
         */
        explicit DevelopmentLogger(LogLevel level = LogLevel::ALL);

        /**
         * An override to include the file, function, and line number of the log message, in addition to everything else.
         */
        String getLogMessage(const LogEntry& entry) const override;
    };

}

#endif //ABRAHAM_DEVELOPMENTLOGGER_HPP
