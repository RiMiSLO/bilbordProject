#include "timebilbord.h"

timeBilbord::timeBilbord()
{
    //std::cout << "Current Time and Date: " << getTime() << std::endl;

}
std::string getTime()
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y %X", now);
    std::string getBack = buffer;
    return getBack;
}

