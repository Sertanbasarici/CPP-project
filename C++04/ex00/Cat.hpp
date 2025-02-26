/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:03:09 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 11:05:52 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
class Cat: public Animal
{
public:
    Cat();
    ~Cat();
    Cat(const Cat& original);
public:
    void makeSound() const;
public:
    Cat&     operator=(const Cat& cat);
};


#endif