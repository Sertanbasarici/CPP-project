/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:58:00 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 07:56:39 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->hitPoints = 100;
	this->energy = 10;
	this->attackDamage = 0;
	std::cout << "Default constructor of ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructar of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->hitPoints = 100;
	this->energy = 10;
	this->attackDamage = 0;
	this->name = name;
	std::cout << "Name constructor of ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout << "copy constructor of ClapTrap called" << std::endl;
	*this = original;
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
	else
		std::cout << "ClapTrap " << this->name << " cannot attack" << std::endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{

	std::cout << "ClapTrap " << this->name << " get damage, causing "<< amount << " of damage" << std::endl;
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name << " get reparied, "<< amount << std::endl;
		this->energy--;
		this->hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << this->name << " cannot be repaired no energy left" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &claptrap)
	{
		this->name = claptrap.getName();
		this->hitPoints = claptrap.getHitPoints();
		this->energy = claptrap.energy;
		this->attackDamage = claptrap.getAttackDamage();
	}
	return *this;
}

void	ClapTrap::setName(const std::string& name)
{
	this->name = name;
}


void	ClapTrap::setAttackDamage(const int& attack)
{
	this->attackDamage = attack;
}

std::string	ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

unsigned int	ClapTrap::getEnergy() const
{
	return (this->energy);
}