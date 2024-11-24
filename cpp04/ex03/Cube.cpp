#include "Cube.hpp"


Cube::Cube()
{
    this->type = "cube";
}

Cube::~Cube()
{

}

Cube* Cube::clone() const
{
    return (new Cube());
}

void Cube::use(ICharacter& target)
{
    std::cout << type << ": * heals " << target.getName() << "'s wounds *" << std::endl;
}
