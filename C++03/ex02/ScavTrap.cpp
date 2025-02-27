/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:01 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 09:30:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->energy = 50;
	this->attackDamage = 20;
    std::cout <<"Defualt constructor of ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout <<"Defualt destructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->energy = 50;
	this->attackDamage = 20;
	this->name = name;
	std::cout << "Name constructor of ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& original): ClapTrap(original)
{
	std::cout <<"Copy constructor of ScavTrap called"<< std::endl;
	*this = original;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hitPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks fearlessly to " << target << ", damage is "<< this->attackDamage << std::endl;
		this->energy--;
	}
	else
		std::cout << "ScavTrap " << this->name << " cannot attack" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{

	std::cout << "ScavTrap " << this->name << " get damage, causing "<< amount << " of damage" << std::endl;
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0)
	{
		std::cout << "ScavTrap " << this->name << " get reparied, "<< amount << std::endl;
		this->energy--;
		this->hitPoints += amount;
	}
	else
		std::cout << "ScavTrap " << this->name << " cannot be repaired no energy left" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap named " << this->name << " guarding gate" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ScavTrap)
{
	std::cout << "Copy assignment of ScavTrap operator called" << std::endl;

	if (this != &ScavTrap)
	{
		this->name = ScavTrap.getName();
		this->hitPoints = ScavTrap.getHitPoints();
		this->energy = ScavTrap.energy;
		this->attackDamage = ScavTrap.getAttackDamage();
	}
	return *this;
}