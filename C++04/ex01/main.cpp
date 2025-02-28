/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 08:07:35 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 10:14:01 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()

{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete i;
		delete j;
	}
	{
		Dog* j = new Dog("i love bones");
		Dog* i = new Dog();

		j->print();
		i->print();
		*i = *j;
		std::cout << "--------------------------------------" << std::endl;
		j->print();
		i->print();
		delete i;
		delete j;
	}
	{
		const Animal* animals[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
}