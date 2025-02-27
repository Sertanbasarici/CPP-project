/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:46:13 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 09:26:05 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap asd;
	ClapTrap trap1 = ClapTrap("firstOne");
	ScavTrap trap2 = ScavTrap("guardWatcher");
	trap2.guardGate();
	for (int i = 0;i < 50;i++)
		trap2.attack("ahmet");
	std::cout << "Energy: " << trap2.getEnergy() << std::endl;
	trap2.attack("ahmet");
	trap1.attack("Enemy");
	trap2.attack("Enemy2");
	trap2.guardGate();
	std::cout << "Energy: " << trap1.getEnergy() << std::endl;
}