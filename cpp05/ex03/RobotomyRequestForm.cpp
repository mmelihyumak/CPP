#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& source) : AForm(source) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& source){
	_target = source._target;
	return *this;
}

std::string RobotomyRequestForm::getTarget() const{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (this->_is_signed == false)
		throw AForm::AFormIsNotSigned();
	if (executor.getGrade() > this->_toExecGrade)
		throw AForm::GradeTooLowException();
	else{
		srand(time(0));
		if (rand() % 2 == 1)
			std::cout << _target + " has been robotomized!" << std::endl;
		else
			std::cout << _target + " robotomy failed!" << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& source){
	os << source.getTarget() << source.getName() << source.getToSignGrade() << source.getToExecGrade() << std::endl;
	return os;
}