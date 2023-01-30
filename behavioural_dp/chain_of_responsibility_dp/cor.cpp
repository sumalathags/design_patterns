#include "cor.hpp"

int main()
{
    LoggerChain chain;
    chain.addLogger(new ConsoleLogger);
    chain.addLogger(new FileLogger);
    chain.addLogger(new EmailLogger);

    // chain.log(LogLevel::INFO, "Info message");
    // chain.log(LogLevel::WARNING, "Warning message");
    // chain.log(LogLevel::ERROR, "Error message");
    chain.log(LogLevel::DEBUG, "Debug message");

    return 0;
}
