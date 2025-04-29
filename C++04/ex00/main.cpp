/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:07:35 by sebasari          #+#    #+#             */
/*   Updated: 2025/04/29 19:04:15 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
// 
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //output will be the cat sound!
    // j->makeSound();
    // meta->makeSound();
    // 
    // delete meta;
    // delete j;
    // delete i;
    const WrongAnimal *meta = new WrongAnimal();
    const WrongCat *i = new WrongCat();
    meta->makeSound();
    i->makeSound(); //output will be the cat sound!
    delete meta;
    delete i;
    return 0;
}