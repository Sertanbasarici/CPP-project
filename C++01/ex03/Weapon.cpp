/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:53:29 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 06:20:39 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}
Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon disarmed " << std::endl;
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}

std::string Weapon::getType() const
{
	return (this->type);
}