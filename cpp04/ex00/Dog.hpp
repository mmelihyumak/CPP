#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		~Dog();
		Dog(std::string type);
		Dog(const Dog& cat);
		Dog& operator=(const Dog& cat);
		void makeSound() const;
};

#endif