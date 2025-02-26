#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(value * (1 << fractionalBits));
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
	return this->fixedPointNumber;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointNumber = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixedPointNumber) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->fixedPointNumber >> fractionalBits;
}

bool	Fixed::operator<(const Fixed& fixed) const
{
	return (this->fixedPointNumber < fixed.fixedPointNumber);
}

bool	Fixed::operator>(const Fixed& fixed) const
{
	return (this->fixedPointNumber > fixed.fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed& fixed) const
{
	return this->fixedPointNumber >= fixed.fixedPointNumber;
}

bool	Fixed::operator<=(const Fixed& fixed) const
{
	return this->fixedPointNumber <= fixed.fixedPointNumber;
}

bool	Fixed::operator==(const Fixed& fixed) const
{
	return this->fixedPointNumber == fixed.fixedPointNumber;
}

bool	Fixed::operator!=(const Fixed& fixed) const
{
	return this->fixedPointNumber != fixed.fixedPointNumber;
}

Fixed	Fixed::operator+(const Fixed& fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed& fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed& fixed) const
{
	return Fixed((this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& fixed) const
{
	return Fixed((this->toFloat() / fixed.toFloat()));
}

Fixed	Fixed::operator++()
{
	this->fixedPointNumber++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedPointNumber++;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedPointNumber--;
	return (temp);
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream &COUT,const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return COUT;
}