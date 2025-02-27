/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 01:21:30 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 09:19:49 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	//ClapTrap trap1 = ClapTrap("Real One");
	ScavTrap trap2 = ScavTrap("Scav One");
	FragTrap trap3 = FragTrap("Frag One");
	//trap1.attack("Enemy");
	//trap2.attack("Scav Enemy");
	//trap3.attack("Frag Enemy");
	//ClapTrap copy1(trap1);
	//ScavTrap copy2(trap2);
	FragTrap copy3(trap3);
	copy3.setName("cabir");
	trap2.guardGate();
	for (int i = 0;i < 50;i++)
		trap2.attack("ahmet");
	std::cout << "Energy: " << trap2.getEnergy() << std::endl;
	trap2.attack("ahmet");
	for (int i = 0;i < 100;i++)
		trap3.attack("ahmet");
	std::cout << "Energy: " << trap3.getEnergy() << std::endl;
	trap3.attack("ahmet");
	copy3.highFivesGuys();
	for (int i = 0;i < 100;i++)
		copy3.attack("ahmet");
	std::cout << "Energy: " << copy3.getEnergy() << std::endl;
	copy3.attack("ahmet");
	copy3.highFivesGuys();
	// trap2.guardGate();
	// copy1.beRepaired(10);
}