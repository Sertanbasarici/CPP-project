/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:04 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/20 17:15:48 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class ScapTrap: public ClapTrap
{
public:
	ScapTrap();
	~ScapTrap();
	ScapTrap(const ClapTrap& original);
	void	attack(const std::string& target);
	void	guardGata();
	ScapTrap& ScapTrap::operator=(const ClapTrap& claptrap);
};
#endif