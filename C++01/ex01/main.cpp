/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:08:57 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 11:27:29 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(ZOMBIE_NUM, "Exp");
	for (int i = 0;i<ZOMBIE_NUM;i++)
		zombie[i].announce();
	delete[] zombie;
}
