#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& source) : AForm(source) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& source){
	_target = source._target;
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->_is_signed != true)
		throw AForm::AFormIsNotSigned();
	if (executor.getGrade() > this->_toExecGrade)
		throw AForm::GradeTooLowException();
	else{
		std::ofstream file(this->_target + "_shrubbery");
		if (file.is_open()){
			file << 
"               * \n"
"              *** \n"
"             ***** \n"
"            ******* \n"
"           ********* \n"
"          *********** \n"
"         ************* \n"
"        *************** \n"
"       ***************** \n"
"      ******************* \n"
"     ********************* \n"
"    *********************** \n"
"   ************************* \n"
"  *************************** \n"
" ***************************** \n"
"*******************************\n"
"               |               \n" << std::endl;
			file.close();
		}else {
			throw ShrubberyCreationForm::FileCouldntOpen();
		}
	}
}

const char* ShrubberyCreationForm::FileCouldntOpen::what() const throw(){
	return "File couldn't open!";
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& source){
	os << source.getTarget() << source.getName() << source.getToSignGrade() << source.getToExecGrade() << std::endl;
	return os;
}