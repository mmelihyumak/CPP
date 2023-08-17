#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string _name;
		bool _is_signed;
		const int _toSignGrade;
		const int _toExecGrade;

	public:
		Form();
		~Form();
		Form(const Form& source);
		Form& operator=(const Form& source);
		Form(std::string name, int toSignGrade, int toExecGrade);
		std::string getName() const;
		bool getIsSigned() const;
		int getToSignGrade() const;
		int getToExecGrade() const;
		void beSigned(const Bureaucrat& bureaucrat);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif