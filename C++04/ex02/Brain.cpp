/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:13:13 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/28 09:29:28 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor called for Brain" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain" << std::endl;
}

Brain::Brain(const Brain& other)
{
	*this = other;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.getIdea(i);
	return *this;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return this->ideas[i];
	return NULL;
}

void Brain::setIdea(const std::string idea, int i)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
		
}