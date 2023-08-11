#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    ShrubberyCreationForm scForm("sc");
    Bureaucrat melih("melih", 40);
    melih.signForm(scForm);
    melih.executeForm(scForm);
    return (0);
}