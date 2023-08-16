#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreationForm);
		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif