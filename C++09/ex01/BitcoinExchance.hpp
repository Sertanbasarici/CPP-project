#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib> 


class BitcoinExchance
{
private:

    std::map<std::string, double> dataB;
public:
    BitcoinExchance();
    ~BitcoinExchance();
    BitcoinExchance(BitcoinExchance const &original);
public:
    bool begin();
    void AddToMyMap(std::ifstream &db);
    bool checkInput();
    void macthTheValue();
public:
    BitcoinExchance& operator=(BitcoinExchance const &other);
};