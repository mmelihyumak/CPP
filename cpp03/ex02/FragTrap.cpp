#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    this->name = fragTrap.name;
    this->hitPoints = fragTrap.hitPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->attackDamage = fragTrap.attackDamage;
    return (*this);
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "FragTrap " + this->name + " high five!" << std::endl;
}