/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:04 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 00:41:56 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& original);
public:
	void	attack(const std::string& target);
	void	guardGate();
public:
	ScavTrap& operator=(const ScavTrap& claptrap);
};
#endif