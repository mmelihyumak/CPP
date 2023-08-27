#include "Span.hpp"

int main(){

	Span span(5);
	std::cout << span << std::endl;
	span.addNumber(5);
	std::cout << span << std::endl;
	return 0;
}