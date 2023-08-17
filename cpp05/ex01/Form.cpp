#include "Form.hpp"

Form::Form() : _name("Default"), _toSignGrade(150), _toExecGrade(150) {
	_is_signed = false;
}

Form::~Form(){}

Form::Form(const Form& source) : _name(source._name), _toSignGrade(source._toSignGrade), _toExecGrade(source._toExecGrade) {
	*this = source;
}

Form& Form::operator=(const Form& source){
	_is_signed = source._is_signed;
	return *this;
}

Form::Form(std::string name, int toSignGrade, int toExecGrade) : _name(name), _toSignGrade(toSignGrade), _toExecGrade(toExecGrade){
	if (_toSignGrade > 150 || _toExecGrade > 150)
		throw Form::GradeTooLowException();
	else if (_toSignGrade < 1 || _toExecGrade < 1)
		throw Form::GradeTooHighException();
	_is_signed = false;
}

std::string Form::getName() const{
	return _name;
}

bool Form::getIsSigned() const{
	return _is_signed;
}

int Form::getToSignGrade() const{
	return _toSignGrade;
}

int Form::getToExecGrade() const{
	return _toExecGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _toSignGrade)
		throw Form::GradeTooLowException();
	else
		_is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << form.getName() << ", is signed-> " << form.getIsSigned()<< ", sign grade-> " << form.getToSignGrade() << ", exec grade-> " << form.getToExecGrade(); 
	return os;
}
