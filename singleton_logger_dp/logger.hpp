#ifndef CUSTOM_Logger_H
#define CUSTOM_Logger_H
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
using namespace std;

/**
*   Singleton Logger Class.
*/
class Logger
{
public:
    /**
    *   Logs a message
    *   @param sMessage message to be logged.
    */
    void Log(const std::string& sMessage);
    
    /**
    *   << overloaded function to Logs a message
    *   @param sMessage message to be logged.
    */
    Logger& operator<<(const string& sMessage);
    /**
    *   Funtion to create the instance of logger class.
    *   @return singleton object of Logger class..
    */
    static Logger* GetLogger();
private:
   
    /**
    *   Log file name.
    **/
    static const std::string log_file_;
    /**
    *   Singleton logger class object pointer.
    **/
    static Logger* logger_instance_;
    /**
    *   Log file stream object.
    **/
    static ofstream logfile_ss;
};
#endif