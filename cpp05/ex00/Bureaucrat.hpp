#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& source);
		Bureaucrat& operator=(const Bureaucrat& source);
		Bureaucrat(std::string name, int grade);
		std::string getName() const;
		int getGrade() const;

		void incrementGrade(int n);
		void decrementGrade(int n);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& source);

#endif