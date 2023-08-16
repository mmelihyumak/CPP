#ifndef PRESINDENTIALPARDONFORM_HPP
# define PRESINDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
		PresidentialPardonForm(std::string target);
		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif