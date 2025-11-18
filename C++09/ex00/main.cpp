#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Error: The program requires exactly one argument." << std::endl, 1);
    BitcoinExchange exchange;

    exchange.readFromDB();
    exchange.readFromFile(av[1]);
}