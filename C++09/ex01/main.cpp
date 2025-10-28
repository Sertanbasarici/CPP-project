#include "BitcoinExchance.hpp"


int main(int argn, char *argv[])
{
    if (argn != 2)
        std::cout << "Invalid number of arguments "<< std::endl;
    BitcoinExchance AllData;
    if (!AllData.begin())
        return (1);
    if (!AllData.checkInput())
        return (1);
}