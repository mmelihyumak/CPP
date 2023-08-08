#include "AForm.hpp"

AForm::AForm() : name("Default"), signGrade(150), execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
	this->is_signed = false;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooLowException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooHighException();
	this->is_signed = false;
}

AForm::AForm(const AForm& aForm) : name(aForm.name), signGrade(aForm.signGrade), execGrade(aForm.execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = aForm;
}

AForm& AForm::operator=(const AForm& aForm)
{
	std::cout << "Form '=' operator called" << std::endl;
	this->is_signed = aForm.is_signed;
	return *this;
}

const std::string AForm::getName()
{
	return this->name;
}

bool AForm::getIsSigned()
{
	return this->is_signed;
}

int AForm::getSignGrade()
{
	return this->signGrade;
}

int AForm::getExecGrade()
{
	return this->execGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->signGrade)
		throw AForm::GradeTooHighException();
	else if (bureaucrat.getGrade() > this->execGrade)
		throw AForm::GradeTooLowException();
	if (this->is_signed == false)
		this->is_signed = true;
	else
		std::cout << this->name + " is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, AForm& aForm)
{
	os << "Name-> " << aForm.getName() << " Is signed-> " << aForm.getIsSigned()
		<< " SignGrade-> " << aForm.getSignGrade() << " ExecGrade-> " << aForm.getExecGrade();
	return os;
}