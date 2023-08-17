#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	try
	{
		Bureaucrat melih("melih", 138);
		ShrubberyCreationForm sc("sc");
		Intern intern;
		melih.signForm(sc);
		melih.executeForm(sc);
		AForm *form;
		form = intern.makeForm("shrubbery creation", "melih");
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}