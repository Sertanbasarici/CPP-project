/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:04:27 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 18:06:22 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zombie1 = newZombie("Experiment1");
	zombie1->announce();
	randomChump("Exprerimet2");
	delete zombie1;
	return (0);
}