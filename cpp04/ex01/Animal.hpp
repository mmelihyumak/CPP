#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(Animal &animal);
		Animal& operator=(Animal &animal);
		virtual ~Animal();
		std::string getType(void) const;
		virtual void makeSound() const;
};

#endif