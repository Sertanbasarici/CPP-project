/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:23:41 by sebasari          #+#    #+#             */
/*   Updated: 2025/09/15 14:50:31 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <limits>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &)
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &)
{
    return *this;
}

//------------ CHAR HELPER --------------------

static bool isPrintableChar(int v)
{
    return (v >= 32 && v <= 126);
}

static bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

static bool isCharLiteral(const std::string &s)
{
    return (s.size() == 1 && !isDigit(s[0]));
}

static void printCharFromCharLiteral(const std::string &literal)
{
    char c = literal[0];
    int  ascii = static_cast<int>(c);

    // char:
    std::cout << "char: ";
    if (isPrintableChar(ascii)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

    // int:
    std::cout << "int: " << ascii << std::endl;

    // float:
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(ascii) << "f" << std::endl;

    // double:
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(ascii) << std::endl;
}

//---------------- INT HElPER---------------//
static bool isIntLiteral(const std::string& s)
{
    if (s.empty()) return false;

    std::size_t i = 0;
    if (s[0] == '+' || s[0] == '-')
    {
        if (s.size() == 1)
            return false;
        i = 1;
    }
    for (; i < s.size(); ++i)
    {
        if (!isDigit(s[i]))
            return false;
    }
    return true;
}


static void printIntFromIntLiteral(const std::string &literal)
{
    std::istringstream iss(literal);
    long lv;
    iss >> lv;

   if (iss.fail() || !iss.eof())
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }
    if (lv < INT_MIN || lv > INT_MAX)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(lv) << "f\n";
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(lv) << "\n";
        return;
    }

    // Buraya gelindiyse int sınırları içinde
    int value = static_cast<int>(lv);

    // Char yazdır
    std::cout << "char: ";
    if (value < 0 || value > 255) {
        std::cout << "impossible\n";
    } else if (!isPrintableChar(value)) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }
    std::cout << "int: " << value << "\n";
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << "\n";
}


static bool isFloatLiteral(const std::string &s)
{
    if (s.size() < 3)
        return false;
    if (s[s.size() -1] != 'f')
        return false;
    bool bdot = false;
    bool fdot = false;
    int  cdot = 0;
    std::size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s.size() < 4)
            return false;
        i++;
    }
    for (;i < s.size() -1;i++)
    {
        if (s[i] == '.')
        {
            cdot++; 
            if (i != 0 )
                if (isDigit(s[i - 1]))
                    bdot = true;
            if (i + 1 < s.size() - 1 && isDigit(s[i + 1]))
                fdot = true;
        }
        else if (!isDigit(s[i]))
            return false;
    }
    if (cdot != 1)
        return false;
    if (!bdot && !fdot)
        return false;
    return true;   
}

static bool isPseudoFloat(const std::string &s)
{
    return (s == "nanf" || s == "+inff" || s == "-inff");
}


void ScalarConverter::convert(const std::string &literal)
{
    if (isCharLiteral(literal))
    {
        printCharFromCharLiteral(literal);
        return;
    }
    if (isIntLiteral(literal))
    {
        printIntFromIntLiteral(literal);
        return;
    }
    if (isFloatLiteral(literal))
    {
        return;
    }
}
