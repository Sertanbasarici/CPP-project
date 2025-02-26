/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:03:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:05:57 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"
class Dog: public Animal
{
public:
    Dog();
    ~Dog();
    Dog(const Dog& original);
public:
    void        makeSound() const;
public:
    Dog&     operator=(const Dog& dog);
};


#endif