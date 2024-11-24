#include "AMateria.hpp"

AMateria::AMateria()
{
    
}

AMateria::AMateria(const std::string& type)
{
    this->type = type;
}

AMateria::AMateria(const AMateria& aMateria)
{
    this->type = aMateria.type;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
    this->type = aMateria.type;
    return (*this);
}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const 
{
    return this->type;
}