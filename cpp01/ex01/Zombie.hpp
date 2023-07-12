/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melih <melih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 23:59:09 by melih             #+#    #+#             */
/*   Updated: 2023/07/08 17:15:14 by melih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{	
	private:
		std::string	name;

	public:
		void	setName(std::string name);
		void	announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

#endif