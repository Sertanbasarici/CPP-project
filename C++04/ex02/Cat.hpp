/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:03:09 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 09:14:31 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain* brain;
public:
    Cat();
    ~Cat();
    Cat(const std::string ideas);
    Cat(const Cat& original);
public:
    void print();
    void makeSound() const;
public:
    Cat&    operator=(const Cat& cat);
};


#endif