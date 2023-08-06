#include "Form.hpp"

Form::Form() : name("Default"), signGrade(1), execGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
	this->is_signed = false;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), signGrade(signGrade), execGrade(execGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooLowException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooHighException();
	this->is_signed = false;
}

Form::Form(const Form& form) : name(form.name), signGrade(form.signGrade), execGrade(form.execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = form;
}

Form& Form::operator=(const Form& form)
{
	std::cout << "Form '=' operator called" << std::endl;
	this->is_signed = form.is_signed;
	return *this;
}

const std::string Form::getName()
{
	return this->name;
}

bool Form::getIsSigned()
{
	return this->is_signed;
}

int Form::getSignGrade()
{
	return this->signGrade;
}

int Form::getExecGrade()
{
	return this->execGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->signGrade)
		throw Form::GradeTooHighException();
	else if (bureaucrat.getGrade() > this->execGrade)
		throw Form::GradeTooLowException();
	if (this->is_signed == false)
		this->is_signed = true;
	else
		std::cout << this->name + " is already signed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os << "Name-> " << form.getName() << " Is signed-> " << form.getIsSigned()
		<< " SignGrade-> " << form.getSignGrade() << " ExecGrade-> " << form.getExecGrade();
	return os;
}