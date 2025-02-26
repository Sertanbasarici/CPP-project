/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:46:44 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 00:09:30 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
class ClapTrap
{
private:
	std::string		name;
	unsigned int	hitPoints;
	unsigned int	energy;
	unsigned int	attackDamage;
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& original);
	ClapTrap(std::string name);
public:
	void			setName(const std::string& name);
	void			setAttackDamage(const int& attack);
	std::string		getName() const;
	unsigned int	getHitPoints() const;
	unsigned int	getEnergy() const;
	unsigned int	getAttackDamage() const;
public:
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
public:
	ClapTrap&		operator=(const ClapTrap& fixed);
};

#endif