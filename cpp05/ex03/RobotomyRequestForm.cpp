#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source) {
	*this = source;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source){
	AForm::operator=(source);
	this->target = source.target;
	return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > toSignGrade)
		throw AForm::GradeTooLowException();
	else
		this->is_signed = true;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (this->is_signed == false)
		throw AForm::FormIsNotSigned();
	if (executor.getGrade() > toExecGrade)
		throw AForm::GradeTooLowException();
	else{
		srand(time(0));
		std::cout << "Drilling noises..." << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->target + " has been robotomized successfully!" << std::endl;
		else
			std::cout << this->target + " robotomization failed!" << std::endl;
	}
}