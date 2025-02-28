/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:15:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 10:12:14 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() 
{
    std::cout << "Default Cat constructor called" << std::endl;
    this->brain = new Brain();
    for (int i = 0;i<100;i++)
        this->brain->setIdea("I think i am a cat", i);
    this->type = "Cat";
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Default Cat Destructor called" << std::endl;
}

Cat::Cat(const std::string idea)
{
    std::cout << "Idea cat constructor called" << std::endl;
    this->brain = new Brain();
    for (int i = 0;i < 100;i++)
        this->brain->setIdea(idea, i);
    this->type = "Cat";
}

Cat::Cat(const Cat& original): Animal(original) 
{
    std::cout << "Copy Cat constructor called" << std::endl;
    this->brain = original.brain;
    this->type = original.type;
}

void Cat::makeSound() const
{
    std::cout << "Meaw" << std::endl;
}

void    Cat::print()
{
    for (int i = 0; i < 100 ; i++)
        std::cout << this->brain->getIdea(i) << std::endl;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Copy Assignment of Cat operator called" << std::endl;
    if (this != &cat)
    {
        *(this->brain) = *(cat.brain);
        this->type = cat.type;
    }
    return *this;
}

