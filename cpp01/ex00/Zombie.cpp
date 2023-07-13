#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default Constructor called" << std::endl;

}

Zombie::Zombie(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Destructor called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
