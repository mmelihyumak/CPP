#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(std::string type)
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = type;
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat '=' operator called" << std::endl;
	this->type = cat.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}