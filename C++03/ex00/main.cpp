/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:46:13 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/27 07:55:25 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{	
    ClapTrap trap1 = ClapTrap("Real One");
	trap1.attack("Enemy");
	trap1.attack("Enemy");
	trap1.attack("Enemy");
	trap1.attack("Enemy");
	trap1.attack("Enemy");
	trap1.attack("Enemy");
	trap1.takeDamage(20);
	trap1.beRepaired(1);
	trap1.setAttackDamage(13);
	trap1.attack("Enemy");
	std::cout << "Energy: "<< trap1.getEnergy()<< std::endl;
	std::cout << "Health: "<< trap1.getHitPoints()<< std::endl;
	// std::cout << "energy: " << trap1.getEnergy() << std::endl;
	// trap1.setAttackDamage(22);
    // std::cout <<"energy: " << trap1.getEnergy() << std::endl;
	// trap1.attack("Nemesis");
	// trap1.takeDamage(5);
	// trap1.beRepaired(1);
    // std::cout <<"energy: " << trap1.getEnergy() << std::endl;
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
	// trap1.beRepaired(1);
    // std::cout <<"energy: " << trap1.getEnergy() << std::endl;
    // std::cout <<"health: " << trap1.getHitPoints() << std::endl;
	// trap1.takeDamage(60);
	// trap1.beRepaired(40);
    // std::cout <<"health: " << trap1.getHitPoints() << std::endl;
}