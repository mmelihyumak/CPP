#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat& cat)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
	std::cout << "Cat '=' operator called" << std::endl;
	this->type = cat.type;
	*(this->brain) = *(cat.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}