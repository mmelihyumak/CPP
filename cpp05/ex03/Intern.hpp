#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& source);
		Intern& operator=(const Intern& source);
		AForm* makeForm(std::string formName, std::string target);
		class FormNameIsWrong : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

#endif