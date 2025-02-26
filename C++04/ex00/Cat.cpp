/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 10:26:03 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() 
{
    std::cout << "Default Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Default Cat Destructor called" << std::endl;
}

Cat::Cat(const Cat& original): Animal(original) 
{
    std::cout << "Copy Cat constructor called" << std::endl;
    this->type = original.type;
}

void Cat::makeSound() const
{
    std::cout << "Meaw" << std::endl;    
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Copy Assignment of Cat operator called" << std::endl;
    if (this != &cat)
    {
        this->type = cat.type;
    }
    return *this;
}