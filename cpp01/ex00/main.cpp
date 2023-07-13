/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyumak <muyumak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:42:17 by melih             #+#    #+#             */
/*   Updated: 2023/07/13 20:29:21 by muyumak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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