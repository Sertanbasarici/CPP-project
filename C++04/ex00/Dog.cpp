/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:22:11 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:40:05 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() 
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Default Dog Destructor called" << std::endl;
}

Dog::Dog(const Dog& original): Animal(original) 
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->type = original.type;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;    
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Copy Assignment of Cat operator called" << std::endl;
    if (this != &dog)
    {
        this->type = dog.type;
    }
    return *this;
}