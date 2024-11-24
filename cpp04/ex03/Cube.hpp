#pragma once

#include <iostream>
#include "AMateria.hpp"


class Cube : public AMateria
{

    private:
        std::string type;


    public:
        Cube();
        ~Cube();
        Cube* clone() const;
        void use(ICharacter& target);

};