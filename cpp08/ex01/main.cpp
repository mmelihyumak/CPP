#include "Span.hpp"

int main(){

{
	/*Span span(5);
	//std::cout << span << std::endl;
	span.addNumber(5);

	span.addNumber(-5);
	span.addNumber(45);
	span.addNumber(15);

	span.addNumbers(20000);


	std::cout << "Size: " << span.getNumbers().size() << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;*/
}
{
	Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
}
	//std::cout << span << std::endl;
	return 0;
}