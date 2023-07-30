#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void printAttributes(const ClapTrap& clapTrap)
{
    std::cout << "\nName-> " + clapTrap.getName() + "\nattackDamage-> "
        << clapTrap.getAttackDamage() << "\nenergyPoints-> " << clapTrap.getEnergyPoints()
            << "\nhitPoints-> " << clapTrap.getHitPoints() << std::endl << std::endl;
}

int main()
{
    FragTrap clapTrap("melih");

    FragTrap clapTrap2("mustafa");

    printAttributes(clapTrap);
    printAttributes(clapTrap2);

    clapTrap.attack("mustafa");
    clapTrap2.takeDamage(3);

    printAttributes(clapTrap);
    printAttributes(clapTrap2);

    clapTrap2.beRepaired(2);
    
    printAttributes(clapTrap2);

    clapTrap.highFiveGuys();
    return (0);
}