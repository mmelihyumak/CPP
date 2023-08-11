#include "Form.hpp"

Form::Form() : name("Default"), toSignGrade(150), toExecGrade(150) {
	this->is_signed = false;
}

Form::~Form(){}

Form::Form(std::string name, int toSignGrade, int toExecGrade) : name(name), toSignGrade(toSignGrade), toExecGrade(toExecGrade){
	if (toSignGrade < 1 || toExecGrade < 1)
		throw Form::GradeTooHighException();
	if (toSignGrade > 150 || toExecGrade > 150)
		throw Form::GradeTooLowException();
	this->is_signed = false;
} 

Form::Form(const Form& form) : name(form.name), toSignGrade(form.toSignGrade), toExecGrade(form.toExecGrade) {
	*this = form;
}

Form& Form::operator=(const Form& form){
	this->is_signed = form.is_signed;
	return *this;
}

std::string Form::getName(){
	return this->name;
}

bool Form::getIsSigned(){
	return this->is_signed;
}

int Form::getToSignGrade(){
	return this->toSignGrade;
}

int Form::getToExecGrade(){
	return this->toExecGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->getToSignGrade())
		throw Form::GradeTooLowException();
	else{
		if (this->is_signed == true)
			std::cout << " is already signed!" << std::endl;
		else
			this->is_signed = true;
	}
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade is to high!";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, Form& form){
	os << form.getName() << " is signed: " << form.getIsSigned()
		<< " to sign grade: " << form.getToSignGrade() << " to exec grade " << form.getToExecGrade();
	return os; 
}

