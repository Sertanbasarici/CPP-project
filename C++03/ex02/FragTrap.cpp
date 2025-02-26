/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:31:24 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 01:36:22 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->energy = 50;
	this->attackDamage = 30;
    std::cout <<"Defualt constructor of FragTrap called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout <<"Defualt destructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->energy = 50;
	this->attackDamage = 30;
	this->name = name;
	std::cout << "Name constructor of FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& original): ClapTrap(original)
{
    std::cout <<"Copy constructor of FragTrap called"<< std::endl;
    *this = original;
}

FragTrap& FragTrap::operator=(const FragTrap& ScavTrap)
{
	std::cout << "Copy assignment of FragTrap operator called" << std::endl;

	if (this != &ScavTrap)
	{
		this->name = ScavTrap.getName();
		this->hitPoints = ScavTrap.getHitPoints();
		this->energy = ScavTrap.energy;
		this->attackDamage = ScavTrap.getAttackDamage();
	}
	return *this;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap named " << this->name << " gives everyone high fives"<< std::endl;
}