/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 02:10:45 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/12 18:14:27 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define ZOMBIE_NUM 5

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
public:
	void			announce(void);
	void			setName(std::string& name);
	std::string		getName(void);
};

Zombie* zombieHorde( int N, std::string name );
#endif