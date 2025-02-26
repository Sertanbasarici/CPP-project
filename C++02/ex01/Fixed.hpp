/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:43:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 02:33:06 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					fixedPointNumber;
	static const int	fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& original);
	Fixed(const int value);
	Fixed(const float value);
public:
	float	toFloat() const;
	int		toInt() const;
	void	setRawBits(int const raw);
	int		getRawBits() const;
public:
	Fixed&	operator=(const Fixed& fixed);
};

std::ostream& operator<<(std::ostream &COUT,const Fixed& fixed);

#endif
