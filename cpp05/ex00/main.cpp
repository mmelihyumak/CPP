#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat melih("melih", 151);
        std::cout << melih << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat melih("melih", -15);
        std::cout << melih << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}