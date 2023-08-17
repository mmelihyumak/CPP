#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(const Bureaucrat& source) : _name(source._name) {
	*this = source;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& source){
	_grade = source._grade;
	return *this;
}

std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::signForm(Form& form){
	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName();
	}
	catch(const std::exception& e){
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; 
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& source){
	os << source.getName() << ", bureaucrat grade " << source.getGrade(); 
	return os;
}