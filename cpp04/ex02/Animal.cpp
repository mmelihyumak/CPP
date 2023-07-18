#include "Animal.hpp"

/*Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal &animal)
{
	this->type = animal.type;
}

Animal& Animal::operator=(Animal &animal)
{
	type = animal.type;
	return (*this);
}*/

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*std::string Animal::getType(void) const
{
	std::cout << "getType member function called" << std::endl;
	return (this->type);
}*/
