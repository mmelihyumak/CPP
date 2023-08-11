#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int toSignGrade;
		const int toExecGrade;

	public:
		Form();
		~Form();
		Form(std::string name, int toSignGrade, int toExecGrade);
		Form(const Form& form);
		Form& operator=(const Form& form);
		std::string getName();
		bool getIsSigned();
		int getToSignGrade();
		int getToExecGrade();
		void beSigned(Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form &form);

#endif