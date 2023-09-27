#include "Span.hpp"

int main(){

	try
	{
		Span span(10);

		span.addNumbers(10);

		std::cout << span.shortestSpan() << std::endl;
		std::cout << span.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}