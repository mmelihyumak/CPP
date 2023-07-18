#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat &cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = cat.type;
	this->brain = cat.brain;
}

Cat& Cat::operator=(Cat &cat)
{
	std::cout << "Cat '=' operator called" << std::endl;
	this->brain = cat.brain;
	this->type = cat.type;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}