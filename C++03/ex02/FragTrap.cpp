/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:31:24 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 09:28:04 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->energy = 100;
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

void		FragTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hitPoints > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
	else
		std::cout << "FragTrap " << this->name << " cannot attack" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{

	std::cout << "FragTrap " << this->name << " get damage, causing "<< amount << " of damage" << std::endl;
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0)
	{
		std::cout << "FragTrap " << this->name << " get reparied, "<< amount << std::endl;
		this->energy--;
		this->hitPoints += amount;
	}
	else
		std::cout << "FragTrap " << this->name << " cannot be repaired no energy left" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap named " << this->name << " high fived with friends"<< std::endl;
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