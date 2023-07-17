#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		~Animal();
		std::string getType(void) const;
		void makeSound() const;
};

#endif