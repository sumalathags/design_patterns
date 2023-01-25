
#include "logger.hpp"

const string Logger::log_file_ = "Log.txt";
Logger* Logger::logger_instance_ = NULL;
ofstream Logger::logfile_ss;


Logger* Logger::GetLogger(){
    if (logger_instance_ == NULL){
        logger_instance_ = new Logger();
        logfile_ss.open(log_file_.c_str(), ios::out | ios::app);
    }
    return logger_instance_;
}
 

void Logger::Log(const string& sMessage)
{
    logfile_ss << sMessage << "\n";
}
 
Logger& Logger::operator<<(const string& sMessage)
{
    logfile_ss << sMessage << "\n";
    return *this;
}