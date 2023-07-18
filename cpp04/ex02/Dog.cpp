#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog &dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = dog.type;
	this->brain = dog.brain;
}

Dog& Dog::operator=(Dog &dog)
{
	std::cout << "Dog '=' operator called" << std::endl;
	this->brain = dog.brain;
	this->type = dog.type;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Hav hav" << std::endl;
}