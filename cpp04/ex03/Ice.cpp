#include "Ice.hpp"

Ice::Ice()
{
    this->type = "Ice";
}

Ice::~Ice()
{

}

Ice* Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter& target)
{
    std::cout << type << ": * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
