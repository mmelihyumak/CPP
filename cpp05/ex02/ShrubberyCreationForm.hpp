#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

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
};

#endif