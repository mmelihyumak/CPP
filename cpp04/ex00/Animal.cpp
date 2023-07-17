#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	std::cout << "getType member function called" << std::endl;
	return (this->type);
}

void Animal::makeSound() const
{
	if (this->type == "Dog")
		std::cout << "Hav hav" << std::endl;
	else if (this->type == "Cat")
		std::cout << "Meow meow" << std::endl;
	else
		std::cout << "Animal sound" << std::endl;
}
