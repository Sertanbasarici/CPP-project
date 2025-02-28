/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:22:11 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 10:11:58 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal() 
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->brain = new Brain();
    for (int i = 0;i < 100;i++)
        this->brain->setIdea("I think i am a dog", i);
    this->type = "Dog";
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Default Dog Destructor called" << std::endl;
}

Dog::Dog(const std::string idea)
{
    std::cout << "idea dog constructor called"<< std::endl;
    this->brain = new Brain();
    for (int i = 0; i < 100 ; i++)
        this->brain->setIdea(idea, i);
    this->type = "Dog";
}

Dog::Dog(const Dog& original): Animal(original) 
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->brain = original.brain;
    this->type = original.type;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

void    Dog::print()
{
    for (int i = 0; i < 100; i++)
        std::cout << this->brain->getIdea(i) << std::endl;
}
Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Copy Assignment of Cat operator called" << std::endl;
    if (this != &dog)
    {
        *(this->brain) = *(dog.brain);
        this->type = dog.type;
    }
    return *this;
}