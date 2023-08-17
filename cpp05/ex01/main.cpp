#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	try
	{
		Bureaucrat melih("melih", 111);
		Form b1("b1", 110, 140);
		std::cout << melih << std::endl;
		melih.signForm(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	return 0;
}