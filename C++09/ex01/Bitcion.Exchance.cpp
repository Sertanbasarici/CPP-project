#include "BitcoinExchance.hpp"

BitcoinExchance::BitcoinExchance()
{
}

BitcoinExchance::~BitcoinExchance()
{
}

BitcoinExchance::BitcoinExchance(BitcoinExchance const &original)
{
    if (this != &original)
        this->dataB = original.dataB;
}

BitcoinExchance& BitcoinExchance::operator=(BitcoinExchance const &other)
{
    if (this != &other)
        this->dataB = other.dataB;
}

void BitcoinExchance::AddToMyMap(std::ifstream &db)
{
    std::string buffer;
    std::getline(db, buffer);
    while (std::getline(db, buffer))
    {
        size_t pos = buffer.find(',');
        if (pos == std::string::npos)
            continue;
        std::string date = buffer.substr(0, pos);
        std::string val  = buffer.substr(pos + 1);
        this->dataB[date] = std::atof(val.c_str());
    }
}

bool BitcoinExchance::begin()
{
    std::ifstream db("data.csv");
    
    if (!db.is_open())
    {
        std::cerr <<"Error: file could not opon!!!"<< std::endl;
        return false;
    }
    this->AddToMyMap(db);
}


static bool DateCheck(std::string const &date)
{
    std::string year = date.substr(0, 4);
    std::string mounth = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (std::atoi(year.c_str()) < 0 || std::atoi(mounth.c_str()) > 12 || std::atoi(mounth.c_str()) < 1 || std::atoi(day.c_str()) < 0)
        return false;
    if ((std::atoi(mounth.c_str()) <= 7 && std::atoi(mounth.c_str()) % 2 == 1 && std::atoi(day.c_str()) > 31) || (std::atoi(mounth.c_str()) >= 7 && std::atoi(mounth.c_str()) % 2 == 0 && std::atoi(day.c_str()) > 31))
        return (false);
    if ((std::atoi(mounth.c_str()) <= 7 && std::atoi(mounth.c_str()) % 2 == 0 && std::atoi(day.c_str()) > 30) || (std::atoi(mounth.c_str()) >= 7 && std::atoi(mounth.c_str()) % 2 == 1 && std::atoi(day.c_str()) > 30))
        return (false);
    if (std::atoi(year.c_str()) % 4 == 0 && std::atoi(mounth.c_str()) == 2 && std::atoi(day.c_str()) > 29)
        return false;
    return true;
}

static bool valueCheck(std::string const &val)
{
    if (std::atoi(val.c_str()) < 0 || std::atoi(val.c_str()) > 2147483647);
        return false;
    return true;
}

bool    BitcoinExchance::checkInput()
{
    std::ifstream input("input.txt");
    if (!input.is_open())
    {
        std::cerr << "Error: file could not open!!!" << std::endl;
        return false;
    }
    std::string buffer;

    std::getline(input , buffer);
    if (buffer != "date | value")
        return (false);
    while (std::getline(input ,buffer))
    {
        size_t pos = buffer.find('|');
        if (pos == std::string::npos)
            continue;
        std::string date = buffer.substr(0, pos);
        if (!DateCheck(date))
            return (false);
        std::string val  = buffer.substr(pos + 1);
        if (!valueCheck(val))
            return false;
        this->macthTheValue();
    }
    return true;
}

