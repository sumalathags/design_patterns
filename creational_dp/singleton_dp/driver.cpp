#include <string>
#include "logger.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    string message1 = "logg message 1 ...";
    string message2 = "logg message 2 ...";
    int    nNum = 10;
    Logger::GetLogger()->Log("message to be logged");
    Logger::GetLogger()->Log(message1);

    Logger log_obj;
    log_obj << message2;
 
    return 0;
}