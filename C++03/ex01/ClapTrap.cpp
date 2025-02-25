/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:58:00 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/20 00:49:25 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Default destructar called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& original)
{
	std::cout << "copy constructor called" << std::endl;
	*this = original;
}

void	ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

void	ClapTrap::setHitPoints(const int& getHitPoints)
{
	this->hitPoints = getHitPoints;
}

void	ClapTrap::setEnergy(const int& energy)
{
	this->energy = energy;
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

unsigned int	ClapTrap::getEnergy() const
{
	return (this->energy);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->attackDamage);
}

void		ClapTrap::attack(const std::string& target)
{
	if (this->energy > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "<< this->attackDamage << " points of damage!" << std::endl;
		this->energy--;
	}
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
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &claptrap)
	{
		this->name = claptrap.getName();
		this->hitPoints = claptrap.getHitPoints();
		this->energy = claptrap.getEnergy();
		this->attackDamage = claptrap.getAttackDamage();
	}
	return *this;
}