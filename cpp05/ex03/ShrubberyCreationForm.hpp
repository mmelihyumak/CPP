#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "fstream"

class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
		class FileCouldntOpen : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& source);

#endif