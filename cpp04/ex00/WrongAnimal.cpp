#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal '=' operator called" << std::endl;
	this->type = wrongAnimal.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}