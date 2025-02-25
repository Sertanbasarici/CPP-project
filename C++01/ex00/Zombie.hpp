#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	~Zombie();
public:
	void			setName(std::string name);
	void			announce(void);
	std::string		getName();
};

Zombie*			newZombie(std::string name);
void			randomChump(std::string	name);

#endif