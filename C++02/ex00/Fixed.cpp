/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:31:56 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/18 14:42:37 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed& original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &fixed)
		this->fixedPointNumber = fixed.getRawBits();
	return *this;
}


int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}