#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& source);
		void beSigned(Bureaucrat& bureaucrat);
		void execute(Bureaucrat const & executor) const;
};

#endif