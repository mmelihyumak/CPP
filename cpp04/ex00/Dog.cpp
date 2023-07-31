#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type)
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = type;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog '=' operator called" << std::endl;
	this->type = dog.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}