#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    this->name = clapTrap.name;
    this->hitPoints = clapTrap.hitPoints;
    this->energyPoints = clapTrap.energyPoints;
    this->attackDamage = clapTrap.attackDamage;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " + this->name + " attacks " + target + " causing " << this->attackDamage << " points of damage" << std::endl;
    }
    else
        std::cout << "ClapTrap " + this->name + "'s energy points are too low to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints <= 0)
        std::cout << "ClapTrap " + this->name + " already is dead" << std::endl;
    else
    {
        std::cout << "ClapTrap " + this->name + " takes " << amount << " points of damage" << std::endl;
        this->hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints <= 0)
        std::cout << "ClapTrap " + this->name + "'s energy points are too low to repair" << std::endl;
    else
    {
        std::cout << "ClapTrap " + this->name + " takes " << amount << " points of repair point" << std::endl;
        this->hitPoints += amount;
        this->energyPoints--;
    }
}

std::string ClapTrap::getName(void) const
{
    return (this->name);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->attackDamage);
}

int ClapTrap::getEnergyPoints(void) const
{
    return (this->energyPoints);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->hitPoints);
}
