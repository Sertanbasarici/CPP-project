/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:43:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/26 04:52:19 by sebasari         ###   ########.fr       */
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
	Fixed(const Fixed& original);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
public:
	float	toFloat() const;
	int		toInt() const;
	void	setRawBits(int const raw);
	int		getRawBits() const;
public:
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
public:
	Fixed&	operator=(const Fixed& fixed);
	bool	operator<(const Fixed& fixed) const;
	bool	operator>(const Fixed& fixed) const;
	bool	operator>=(const Fixed& fixed) const;
	bool	operator<=(const Fixed& fixed) const;
	bool	operator==(const Fixed& fixed) const;
	bool	operator!=(const Fixed& fixed) const;
	Fixed	operator+(const Fixed& fixed) const;
	Fixed	operator-(const Fixed& fixed) const;
	Fixed	operator*(const Fixed& fixed) const;
	Fixed	operator/(const Fixed& fixed) const;
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);
};

std::ostream& operator<<(std::ostream &COUT,const Fixed& fixed);

#endif
