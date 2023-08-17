#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& intern){
	*this = intern;
}

Intern& Intern::operator=(const Intern& intern){
	(void)intern;
	return *this;
}

AForm *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    typedef AForm *(*funcPtr)(std::string target);
    std::string formNameArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    funcPtr funcArray[3] = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNameArray[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (funcArray[i])(target);
        }
    }
    std::cout << "Intern can't create " << formName << std::endl;
    return NULL;
}