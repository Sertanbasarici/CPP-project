/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:47:47 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 19:48:59 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	std::cout << this->name << " is gone" << std::endl;
}

void	HumanB::attack()
{
	if (this->weapon->getType() == "")
		std::cout << this->name << " attacks with their bare hands"<< std::endl;
	else
		std::cout << this->name << " attacks with their "<< this->weapon->getType() << std::endl;
}

void	HumanB::setName(std::string	name)
{
	this->name = name;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

std::string HumanB::getName()
{
	return (this->name);
}

Weapon HumanB::getWeapon()
{
	return (*this->weapon);
}