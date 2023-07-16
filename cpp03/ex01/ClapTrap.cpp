#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	this->name = clapTrap.name;
}

void ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	this->name = clapTrap.name;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << "1 points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " loses " << amount << " hit points" << std::endl;
	this->hitPoints--;
	if (this->hitPoints <= 0)
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " hit points " << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

int ClapTrap::gethitPoints(void)
{
	return (this->hitPoints);
}

