#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
    *this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    this->name = scavTrap.name;
    this->hitPoints = scavTrap.hitPoints;
    this->energyPoints = scavTrap.energyPoints;
    this->attackDamage = scavTrap.attackDamage;
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " + this->name + " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ScavTrap " + this->name + " attacks " + target + " causing " << this->attackDamage << " points of damage" << std::endl;
    }
    else
        std::cout << "ScavTrap " + this->name + "'s energy points are too low to attack" << std::endl;
}