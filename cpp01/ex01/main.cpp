/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:59:02 by melih             #+#    #+#             */
/*   Updated: 2023/07/13 21:24:08 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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