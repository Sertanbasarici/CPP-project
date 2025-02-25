/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:06 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 19:48:40 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	HumanA(const std::string& name,Weapon& weapon);
	~HumanA();
public:
	void		attack();
	void		setName(std::string name);
	void		setWeapon(Weapon& weapon);
	std::string	getName();
	Weapon		getWeapon();
};

#endif