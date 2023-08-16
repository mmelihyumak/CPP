#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string name;
		bool is_signed;
		const int toSignGrade;
		const int toExecGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int toSignGrade, int toExecGrade);
		AForm(const AForm& form);
		AForm& operator=(const AForm& form);
		std::string getName();
		bool getIsSigned();
		int getToSignGrade();
		int getToExecGrade();
		virtual void beSigned(Bureaucrat& bureaucrat) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class FormIsNotSigned : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm &form);

#endif