#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("melih");

	clapTrap.attack("mustafa");
	clapTrap.beRepaired(1);
	std::cout << "after repair -> " << clapTrap.gethitPoints() << std::endl;
	clapTrap.takeDamage(1);
	std::cout << "after da -> " << clapTrap.gethitPoints() << std::endl;
	return (0);
}