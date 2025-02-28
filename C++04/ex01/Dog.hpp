/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:03:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 09:12:30 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Brain.hpp"
#include "Animal.hpp"
class Dog: public Animal
{
private:
    Brain *brain;
public:
    Dog();
    ~Dog();
    Dog(const std::string idea);
    Dog(const Dog& original);
public:
    void        print();
    void        makeSound() const;
public:
    Dog&     operator=(const Dog& dog);
};


#endif