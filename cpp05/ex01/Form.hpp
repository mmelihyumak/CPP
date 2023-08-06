#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int signGrade;
		const int execGrade;

	public:
		Form();
		~Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form& form);
		Form& operator=(const Form& form);
		const std::string getName();
		bool getIsSigned();
		int getSignGrade();
		int getExecGrade();
		void beSigned(Bureaucrat& bureaucrat);
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

std::ostream& operator<<(std::ostream& os, const Form&form); 

#endif