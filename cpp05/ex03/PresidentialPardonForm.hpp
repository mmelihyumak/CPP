#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		std::string _target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& source);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& source);

#endif