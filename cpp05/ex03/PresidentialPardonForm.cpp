#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source) {
	*this = source;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source){
	AForm::operator=(source);
	this->target = source.target;
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

void PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > toSignGrade)
		throw AForm::GradeTooLowException();
	else
		this->is_signed = true;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->is_signed == false)
		throw AForm::FormIsNotSigned();
	if (executor.getGrade() > this->toExecGrade)
		throw AForm::GradeTooLowException();
	else{
		std::cout << this->target + " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}