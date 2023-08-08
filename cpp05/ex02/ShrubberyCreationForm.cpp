#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
	std::cout << "ShrubberyCreationForm '=' operator called" << std::endl;
	AForm::operator=(shrubberyCreationForm);
	this->target = shrubberyCreationForm.target;
	return *this;
}
