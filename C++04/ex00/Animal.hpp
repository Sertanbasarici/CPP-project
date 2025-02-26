/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 07:48:30 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:33:51 by sebasari         ###   ########.fr       */
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
    virtual ~Animal();
    Animal(const Animal& original);
public:
    void                setType(const std::string& type);
    std::string         getType() const;
    virtual void        makeSound() const;
public:
    Animal&     operator=(const Animal& animal);
};


#endif