#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		std::string _target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& source);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& source);
		std::string getTarget() const;
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& source);

#endif