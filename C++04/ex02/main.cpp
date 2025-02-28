/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:07:35 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 10:50:02 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()

{
	// Animal a;
	Animal *c = new Cat();
	c->makeSound();
	Animal *d = new Dog();
	d->makeSound();
	delete c;
	delete d;
}