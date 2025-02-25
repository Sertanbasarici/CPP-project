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

std::ostream& operator<<(std::ostream &COUT,const Fixed& fixed)
{
	COUT << fixed.toFloat();
	return COUT;
}

bool	Fixed::operator<(const Fixed& fixed)
{
	return this->fixedPointNumber < fixed.fixedPointNumber;
}

bool	Fixed::operator>(const Fixed& fixed)
{
	return this->fixedPointNumber > fixed.fixedPointNumber;
}

bool	Fixed::operator>=(const Fixed& fixed)
{
	return this->fixedPointNumber >= fixed.fixedPointNumber;
}

bool	Fixed::operator<=(const Fixed& fixed)
{
	return this->fixedPointNumber <= fixed.fixedPointNumber;
}

bool	Fixed::operator==(const Fixed& fixed)
{
	return this->fixedPointNumber == fixed.fixedPointNumber;
}

bool	Fixed::operator!=(const Fixed& fixed)
{
	return this->fixedPointNumber != fixed.fixedPointNumber;
}

Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed temp;
	temp.fixedPointNumber = this->toFloat() + fixed.toFloat();

	return (temp);
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed temp;
	temp.fixedPointNumber = this->toFloat() - fixed.toFloat();

	return (temp);
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed temp;
	temp.fixedPointNumber = this->toFloat() * fixed.toFloat();

	return (temp);
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed temp;
	temp.fixedPointNumber = this->toFloat() / fixed.toFloat();

	return (temp);
}

Fixed	Fixed::operator++()
{
	this->fixedPointNumber++;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(this->fixedPointNumber);
	this->fixedPointNumber++;
	return (this->fixedPointNumber);
}

Fixed	Fixed::operator--()
{
	this->fixedPointNumber--;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(this->fixedPointNumber);
	this->fixedPointNumber--;
	return (this->fixedPointNumber);
}