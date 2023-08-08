#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int signGrade;
		const int execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm& aForm);
		AForm& operator=(const AForm& aForm);
		const std::string getName();
		bool getIsSigned();
		int getSignGrade();
		int getExecGrade();
		virtual void beSigned(Bureaucrat& bureaucrat) = 0;
		class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too high!"; }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw() { return "Grade too low!"; }
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& aForm); 

#endif