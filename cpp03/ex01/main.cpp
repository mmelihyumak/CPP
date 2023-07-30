#include "ScavTrap.hpp"

void printAttributes(const ClapTrap& clapTrap)
{
    std::cout << "\nName-> " + clapTrap.getName() + "\nattackDamage-> "
        << clapTrap.getAttackDamage() << "\nenergyPoints-> " << clapTrap.getEnergyPoints()
            << "\nhitPoints-> " << clapTrap.getHitPoints() << std::endl << std::endl;
}

int main()
{
    ScavTrap clapTrap("melih");

    ScavTrap clapTrap2("mustafa");

    printAttributes(clapTrap);
    printAttributes(clapTrap2);

    clapTrap.attack("mustafa");
    clapTrap2.takeDamage(3);

    printAttributes(clapTrap);
    printAttributes(clapTrap2);

    clapTrap2.beRepaired(2);
    
    printAttributes(clapTrap2);

    clapTrap.guardGate();
    return (0);
}