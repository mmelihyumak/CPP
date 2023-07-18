#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack()
{
	if (this->weapon != NULL)
		std::cout << this->name << "attacks with his " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << "attacks with his hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
