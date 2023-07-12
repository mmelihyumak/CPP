/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:59:02 by melih             #+#    #+#             */
/*   Updated: 2023/07/08 17:16:41 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name);

int	main(int argc, char **argv)
{
	Zombie	*zombie;

	if (argc != 2)
	{
		std::cout << "You must enter a number!" << std::endl;
	}
	int	n = atoi(argv[1]);
	zombie = zombieHorde(n, "melih");
	for (int i = 0; i < n; i++)
		zombie[i].announce();
	delete [] zombie;
	return (0);
}