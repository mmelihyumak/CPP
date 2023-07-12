#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);
		void	setType(std::string type);
		std::string getType(void);
};

#endif