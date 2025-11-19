#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>

// ----------------- helper: trim -----------------
static std::string trim(const std::string &str)
{
    std::string::size_type first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return "";
    std::string::size_type last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

// ----------------- Orthodox Canonical -----------------
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
    this->dataBase = cpy.dataBase;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
    if (this != &cpy)
        this->dataBase = cpy.dataBase;
    return *this;
}

// ----------------- Date & Value helpers -----------------
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    // Format: YYYY-MM-DD  → toplam 10 karakter
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Rakam kontrolü
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year <= 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::parseValue(const std::string &str, double &value) const
{
    std::stringstream ss(str);
    ss >> value;
    if (ss.fail())
        return false;

    // Fazladan karakter olmamalı
    char c;
    if (ss >> c)
        return false;

    return true;
}

// ----------------- data.csv okuma -----------------
void BitcoinExchange::readFromDB()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;

    // header satırını atla
    if (!std::getline(file, line))
        return;

    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date, rateStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, rateStr))
            continue;

        date = trim(date);
        rateStr = trim(rateStr);
        if (date.empty() || rateStr.empty())
            continue;

        double rateD;
        if (!parseValue(rateStr, rateD))
            continue;

        this->dataBase[date] = static_cast<float>(rateD);
    }
}

// ----------------- Tarih bul & yaz -----------------
void BitcoinExchange::findDateAndPrint(const std::string &date, double value) const
{
    if (this->dataBase.empty())
    {
        std::cout << "Error: no database loaded." << std::endl;
        return;
    }

    std::map<std::string, float>::const_iterator it = this->dataBase.find(date);

    if (it != this->dataBase.end())
    {
        std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
        return;
    }

    it = this->dataBase.lower_bound(date);

    // date DB'deki en küçük tarihten bile küçükse
    if (it == this->dataBase.begin())
    {
        std::cout << "Error: no valid date found." << std::endl;
        return;
    }

    // lower_bound ya end() ya da date'ten büyük olabilir → bir önceki lower
    if (it == this->dataBase.end() || it->first > date)
        --it;

    std::cout << date << " => " << value << " = " << (it->second * value) << std::endl;
}

// ----------------- Tek satır kontrol & print -----------------
void BitcoinExchange::checkLineAndPrint(const std::string &line)
{
    std::string trimmed = trim(line);
    if (trimmed.empty())
        return;

    std::string::size_type pos = trimmed.find('|');
    if (pos == std::string::npos)
    {
        std::cout << "Error: bad input => " << trimmed << std::endl;
        return;
    }

    std::string date = trim(trimmed.substr(0, pos));
    std::string valueStr = trim(trimmed.substr(pos + 1));

    if (date.empty() || valueStr.empty())
    {
        std::cout << "Error: bad input => " << trimmed << std::endl;
        return;
    }

    if (!isValidDate(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }

    double value;
    if (!parseValue(valueStr, value))
    {
        std::cout << "Error: bad input => " << trimmed << std::endl;
        return;
    }

    if (value <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    if (value > 1000.0)
    {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }

    findDateAndPrint(date, value);
}

// ----------------- input dosyasını okuma -----------------
void BitcoinExchange::readFromFile(const std::string &fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;

    // input header: "date | value" satırını atla
    if (!std::getline(file, line))
        return;

    while (std::getline(file, line))
        checkLineAndPrint(line);

    file.close();
}
