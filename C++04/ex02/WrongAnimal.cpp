/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:31:33 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 22:32:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "Default WrongAnimal constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default WrongAnimal Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& original)
{
    std::cout << "Copy WrongAnimal constructor called" << std::endl;
    this->type = original.type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Unknown type voice" << std::endl;    
}

void WrongAnimal::setType(const std::string& type)
{
    this->type = type;   
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "Copy Assignment of WrongAnimal operator called" << std::endl;
    if (this != &wrongAnimal)
    {
        this->type = wrongAnimal.type;
    }
    return *this;
}
