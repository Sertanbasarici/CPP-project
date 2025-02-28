/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:48:30 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 10:44:58 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
class Animal
{
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal() = 0;
    Animal(const Animal& original);
public:
    void                setType(const std::string& type);
    std::string         getType() const;
    virtual void        makeSound() const = 0;
public:
    Animal&     operator=(const Animal& animal);
};


#endif