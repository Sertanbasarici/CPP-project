/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:48:13 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 10:26:19 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Default Animal constructor called" << std::endl;
    this->type = "Unknown";
}

Animal::~Animal()
{
    std::cout << "Default Animal Destructor called" << std::endl;
}

Animal::Animal(const Animal& original)
{
    std::cout << "Copy Animal constructor called" << std::endl;
    this->type = original.type;
}

void Animal::makeSound() const
{
    std::cout << "Unknown voice" << std::endl;    
}

void Animal::setType(const std::string& type)
{
    this->type = type;   
}

std::string Animal::getType() const
{
    return this->type;
}

Animal& Animal::operator=(const Animal& animal)
{
    std::cout << "Copy Assignment of Animal operator called" << std::endl;
    if (this != &animal)
    {
        this->type = animal.type;
    }
    return *this;
}
