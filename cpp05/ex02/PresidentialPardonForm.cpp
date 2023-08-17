#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& source) : AForm(source) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& source){
	_target = source._target;
	return *this;
}

std::string PresidentialPardonForm::getTarget() const{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->_is_signed == false)
		throw AForm::AFormIsNotSigned();
	if (executor.getGrade() > this->_toExecGrade)
		throw AForm::GradeTooLowException();
	else{
		std::cout << _target + " has been pardoned by Zaphod BeebleBrox" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& source){
	os << source.getTarget() << source.getName() << source.getToSignGrade() << source.getToExecGrade() << std::endl;
	return os;
}