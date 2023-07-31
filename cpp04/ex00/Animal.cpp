#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& animal)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
	std::cout << "Animal = operator called" << std::endl;
	this->type = animal.type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "There is no animal" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}