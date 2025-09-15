/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:53:19 by sebasari          #+#    #+#             */
/*   Updated: 2025/09/15 13:13:12 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argn, char *argv[])
{
    if (argn != 2)
    {
        std::cerr << "Usage: ./convert <literal>"<< std::endl;
        return (1);
    }
    try 
    {
        ScalarConverter::convert(std::string(argv[1]));
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}