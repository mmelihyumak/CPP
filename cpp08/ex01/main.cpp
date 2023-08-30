#include "Span.hpp"

int main(){

	{
		Span span(40000);
		//std::cout << span << std::endl;
	
		span.addNumbers(40000);

		
		std::cout << "Span: " << span << std::endl;

		//std::cout << "Size: " << span.getNumbers().size() << std::endl;
		try
		{
			std::cout << span.shortestSpan() << std::endl;
			std::cout << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}	
	return 0;
}