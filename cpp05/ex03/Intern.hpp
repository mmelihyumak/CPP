#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern{

	public:
		Intern();
		~Intern();
		Intern(const Intern& internt);
		Intern& operator=(const Intern& intern);
		AForm* makeForm(std::string formName, std::string target);
};

#endif