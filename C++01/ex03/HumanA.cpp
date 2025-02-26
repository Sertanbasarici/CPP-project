/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:47:47 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 06:22:58 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name,Weapon& weapon)
{
	this->weapon = &weapon;
	this->name = name;
}

HumanA::~HumanA()
{
	std::cout << this->name << " is gone" << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their "<< this->weapon->getType() << std::endl;
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

std::string HumanA::getName()
{
	return (this->name);
}

Weapon HumanA::getWeapon()
{
	return (*this->weapon);
}