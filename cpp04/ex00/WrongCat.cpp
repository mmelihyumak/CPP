#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(std::string type)
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->type = type;
}

WrongCat::WrongCat(const WrongCat& wrongCat)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
	std::cout << "WrongCat '=' operator called" << std::endl;
	this->type = wrongCat.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}