/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:42:17 by melih             #+#    #+#             */
/*   Updated: 2023/07/05 23:56:57 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie	*zombie = new Zombie("zombie1");
	Zombie	*zombie2 = newZombie("zombie2");

	zombie->announce();
	zombie2->announce();
	zombie->~Zombie();
	zombie2->~Zombie();
	randomChump("zombie3");
	return (0);
}