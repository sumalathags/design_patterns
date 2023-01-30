#include <iostream>
#include <vector>

enum class LogLevel
{
    DEBUG,
    ERROR,
    WARNING,
    INFO
};

class Logger
{
public:
    virtual ~Logger()                                     = default;
    virtual void log(LogLevel level, std::string message) = 0;
};

class ConsoleLogger : public Logger
{
public:
    void log(LogLevel level, std::string message) override
    {
        switch (level)
        {
        case LogLevel::DEBUG:
            std::cout << "\033[1;34m[DEBUG]\033[0m " << message << std::endl;
            break;
        case LogLevel::INFO:
            std::cout << "[INFO] " << message << std::endl;
            break;
        case LogLevel::WARNING:
            std::cout << "\033[1;33m[WARNING]\033[0m " << message << std::endl;
            break;
        case LogLevel::ERROR:
            std::cout << "\033[1;31m[ERROR]\033[0m " << message << std::endl;
            break;
        }
    }
};

// log only debug and errors to file
class FileLogger : public Logger
{
public:
    void log(LogLevel level, std::string message) override
    {
        if (level > LogLevel::ERROR)
        {
            return;
        }
        std::cout << "File: " << message << std::endl;
    }
};

// send an email if there was an error
class EmailLogger : public Logger
{
public:
    void log(LogLevel level, std::string message) override
    {
        if (level == LogLevel::ERROR)
        {
            std::cout << "Email sent: " << message << std::endl;
        }
    }
};

// chain of responsibility is created here
// responsibility is handed to each logger one after the other
class LoggerChain : public Logger
{
    std::vector<Logger*> loggers;

public:
    void addLogger(Logger* logger) { loggers.push_back(logger); }

    void log(LogLevel level, std::string message) override
    {
        for (Logger* logger : loggers)
        {
            logger->log(level, message);
        }
    }
};
