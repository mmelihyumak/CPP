
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie* zombies = zombieHorde(3, "melih");
	
	for (int i = 0; i < 3; i++)
		zombies[i].announce();
	delete [] zombies;
	return (0);
}