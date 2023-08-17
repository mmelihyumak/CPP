#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	protected:
		const std::string _name;
		bool _is_signed;
		const int _toSignGrade;
		const int _toExecGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm& source);
		AForm& operator=(const AForm& source);
		AForm(std::string name, int toSignGrade, int toExecGrade);
		std::string getName() const;
		bool getIsSigned() const;
		int getToSignGrade() const;
		int getToExecGrade() const;
		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class AFormIsNotSigned : public std::exception{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif