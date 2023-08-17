#include "AForm.hpp"

AForm::AForm() : _name("Default"), _toSignGrade(150), _toExecGrade(150) {
	_is_signed = false;
}

AForm::~AForm(){}

AForm::AForm(const AForm& source) : _name(source._name), _toSignGrade(source._toSignGrade), _toExecGrade(source._toExecGrade) {
	*this = source;
}

AForm& AForm::operator=(const AForm& source){
	_is_signed = source._is_signed;
	return *this;
}

AForm::AForm(std::string name, int toSignGrade, int toExecGrade) : _name(name), _toSignGrade(toSignGrade), _toExecGrade(toExecGrade){
	if (_toSignGrade > 150 || _toExecGrade > 150)
		throw AForm::GradeTooLowException();
	else if (_toSignGrade < 1 || _toExecGrade < 1)
		throw AForm::GradeTooHighException();
	_is_signed = false;
}

std::string AForm::getName() const{
	return _name;
}

bool AForm::getIsSigned() const{
	return _is_signed;
}

int AForm::getToSignGrade() const{
	return _toSignGrade;
}

int AForm::getToExecGrade() const{
	return _toExecGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _toSignGrade)
		throw AForm::GradeTooLowException();
	else
		_is_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

const char* AForm::AFormIsNotSigned::what() const throw(){
	return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form){
	os << form.getName() << ", is signed-> " << form.getIsSigned()<< ", sign grade-> " << form.getToSignGrade() << ", exec grade-> " << form.getToExecGrade(); 
	return os;
}
