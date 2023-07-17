#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
