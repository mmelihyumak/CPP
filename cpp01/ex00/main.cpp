
#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie(std::string name);

int	main()
{
	Zombie *zombie = newZombie("melih");
	zombie->announce();
	delete zombie;
	randomChump("mustafa");
	return (0);
}