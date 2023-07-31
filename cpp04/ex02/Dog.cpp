#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& dog)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
	std::cout << "Dog '=' operator called" << std::endl;
	this->type = dog.type;
	*(this->brain) = *(dog.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}
