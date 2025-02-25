/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:50:14 by sebasari          #+#    #+#             */
/*   Updated: 2025/02/18 14:41:06 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
private:
	int fixedPointNumber;
	static const int fractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& original);
public:
	Fixed& operator=(const Fixed& fixed);
public:
	void	setRawBits(int const raw);
	int		getRawBits(void) const;
};

#endif
