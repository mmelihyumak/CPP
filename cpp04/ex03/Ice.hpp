#pragma once

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{

    private:
        std::string type;


    public:
        Ice();
        ~Ice();
        Ice* clone() const;
        void use(ICharacter& target);

};