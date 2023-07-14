#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointValue = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float floatingPoint)
{
	this->fixedPointValue = roundf(floatingPoint * pow(2, this->fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	fixedPointValue = fixed.fixedPointValue;
}

void Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	fixedPointValue = fixed.fixedPointValue;
}

void Fixed::setRawBits(const int raw)
{
	this->fixedPointValue = raw;
}

const int Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

float Fixed::toFloat(void) const
{
	float value = this->fixedPointValue / pow(2, this->fractionalBits);
	return (value);
}

int Fixed::toInt(void) const
{
	return (this->fixedPointValue >> this->fractionalBits);
}

std::ostream &operator<<(std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}
