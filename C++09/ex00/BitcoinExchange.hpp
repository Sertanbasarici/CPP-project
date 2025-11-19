#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, float> dataBase;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &cpy);
    BitcoinExchange &operator=(const BitcoinExchange &cpy);

public:
    void readFromDB();                        
    void readFromFile(const std::string &);
    void findDateAndPrint(const std::string &date, double value) const;
    void checkLineAndPrint(const std::string &line);

private:
    bool isValidDate(const std::string &date) const;
    bool parseValue(const std::string &str, double &value) const;
};

#endif
