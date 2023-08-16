#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm) : AForm(shrubberyCreationForm)
{
	*this = shrubberyCreationForm;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
	AForm::operator=(shrubberyCreationForm);
	this->target = shrubberyCreationForm.target;
	return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->toSignGrade)
		throw AForm::GradeTooLowException();
	else
		this->is_signed = true;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->is_signed == false)
		throw AForm::FormIsNotSigned();
	if (executor.getGrade() > this->toExecGrade)
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file(this->target + "_shrubbery", std::ios::trunc);
		file << 
"               * \n"
"              *** \n"
"             ***** \n"
"            ******* \n"
"           ********* \n"
"          *********** \n"
"         ************* \n"
"        *************** \n"
"       ***************** \n"
"      ******************* \n"
"     ********************* \n"
"    *********************** \n"
"   ************************* \n"
"  *************************** \n"
" ***************************** \n"
"*******************************\n"
"               |               \n" << std::endl;
	}
}
