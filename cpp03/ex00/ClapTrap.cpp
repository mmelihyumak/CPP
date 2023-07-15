#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	name = clapTrap.name;
}

void ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "Assignment operator called" << std::endl;
	name = clapTrap.name;
}

void attack(const std::string& target)
{
	std::cout << "ClapTrap " << name << "attacks" << target << ", causing" << "1 points of damage!" << std::endl;
}

