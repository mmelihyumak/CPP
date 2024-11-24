#include "Character.hpp"

Character::Character()
{

}

Character::Character(std::string name)
{
    this->name = name;
}

Character::~Character()
{

}

Character::Character(const Character& character)
{
    this->name = character.name;
}

Character& Character::operator=(const Character& character)
{
    this->name = character.name;
    return (*this);
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{

}