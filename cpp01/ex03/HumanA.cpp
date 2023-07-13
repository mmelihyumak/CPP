#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << this->name << " attack with his " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon)
{
	this->weapon = weapon;
	this->name = name;
}
