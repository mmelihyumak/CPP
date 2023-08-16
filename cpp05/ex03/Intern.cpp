#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& source){
	*this = source;
}

Intern& Intern::operator=(const Intern& source){
	return (Intern&)source;
}

AForm* Intern::makeForm(std::string formName, std::string target){
	if (formName == "shrubbery creation"){
		std::cout << "Intern creates " + formName << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "robotomy request"){
		std::cout << "Intern creates " + formName << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (formName == "presidential pardon"){
		std::cout << "Intern creates " + formName << std::endl;
		return new PresidentialPardonForm(target);
	}
	else
		throw Intern::FormNameIsWrong();
	return NULL;
}

const char* Intern::FormNameIsWrong::what() const throw(){
	return "Form name is wrong!";
}