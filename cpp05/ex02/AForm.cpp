#include "AForm.hpp"

AForm::AForm() : name("Default"), toSignGrade(150), toExecGrade(150) {
	this->is_signed = false;
}

AForm::~AForm(){}

AForm::AForm(std::string name, int toSignGrade, int toExecGrade) : name(name), toSignGrade(toSignGrade), toExecGrade(toExecGrade){
	if (toSignGrade < 1 || toExecGrade < 1)
		throw AForm::GradeTooHighException();
	if (toSignGrade > 150 || toExecGrade > 150)
		throw AForm::GradeTooLowException();
	this->is_signed = false;
} 

AForm::AForm(const AForm& form) : name(form.name), toSignGrade(form.toSignGrade), toExecGrade(form.toExecGrade) {
	*this = form;
}

AForm& AForm::operator=(const AForm& form){
	this->is_signed = form.is_signed;
	return *this;
}

std::string AForm::getName(){
	return this->name;
}

bool AForm::getIsSigned(){
	return this->is_signed;
}

int AForm::getToSignGrade(){
	return this->toSignGrade;
}

int AForm::getToExecGrade(){
	return this->toExecGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > this->getToSignGrade())
		throw AForm::GradeTooLowException();
	else{
		if (this->is_signed == true)
			std::cout << " is already signed!" << std::endl;
		else
			this->is_signed = true;
	}
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade is to high!";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, AForm& form){
	os << form.getName() << " is signed: " << form.getIsSigned()
		<< " to sign grade: " << form.getToSignGrade() << " to exec grade " << form.getToExecGrade();
	return os; 
}