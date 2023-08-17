#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

	try
	{
		Bureaucrat melih("melih", 138);
		ShrubberyCreationForm sc("sc");
		melih.signForm(sc);
		melih.executeForm(sc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}