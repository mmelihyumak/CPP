#include "Bureaucrat.hpp"

int main(){

	try
	{
		Bureaucrat melih("melih", 15);
		melih.decrementGrade(150);
		std::cout << melih << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}