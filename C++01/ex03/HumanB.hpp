/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 19:48:52 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	HumanB(const std::string& name);
	~HumanB();
public:
	void		attack();
	void		setName(std::string name);
	void		setWeapon(Weapon& weapon);
	std::string	getName();
	Weapon		getWeapon();
};

#endif