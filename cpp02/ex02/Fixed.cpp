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

int Fixed::getRawBits(void) const
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

bool Fixed::operator>(const Fixed &other) const
{
	std::cout << "> operator called" << std::endl;
	return (fixedPointValue > other.fixedPointValue);
}

bool Fixed::operator<(const Fixed &other) const
{
	std::cout << "< operator called" << std::endl;
	return (fixedPointValue < other.fixedPointValue);
}

bool Fixed::operator>=(const Fixed &other) const
{
	std::cout << ">= operator called" << std::endl;
	return (fixedPointValue >= other.fixedPointValue);
}

bool Fixed::operator<=(const Fixed &other) const
{
	std::cout << "<= operator called" << std::endl;
	return (fixedPointValue <= other.fixedPointValue);
}

bool Fixed::operator==(const Fixed &other) const
{
	std::cout << "== operator called" << std::endl;
	return (fixedPointValue == other.fixedPointValue);
}

bool Fixed::operator!=(const Fixed &other) const
{
	std::cout << "!= operator called" << std::endl;
	return (fixedPointValue != other.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	std::cout << "+ operator called" << std::endl;
	int result = fixedPointValue + other.fixedPointValue;
	return (Fixed(result));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	std::cout << "- operator called" << std::endl;
	int result = fixedPointValue - other.fixedPointValue;
	return (Fixed(result));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	std::cout << "* operator called" << std::endl;
	int result = fixedPointValue * other.fixedPointValue;
	return (Fixed(result));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	std::cout << "/ operator called" << std::endl;
	int result = fixedPointValue / other.fixedPointValue;
	return (Fixed(result));
}

Fixed& Fixed::operator++()
{
	++fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++fixedPointValue;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--fixedPointValue;
	return (temp);
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixedPointValue < fixed2.fixedPointValue) ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixedPointValue > fixed2.fixedPointValue) ? fixed1 : fixed2;
}
