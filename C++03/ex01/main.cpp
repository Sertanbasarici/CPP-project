/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:46:13 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 01:39:23 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap asd;
	ClapTrap trap1 = ClapTrap("firstOne");
	ScavTrap trap2 = ScavTrap("guardWatcher");
	trap1.attack("Enemy");
	trap2.attack("Enemy2");	
	trap2.guardGate();
}