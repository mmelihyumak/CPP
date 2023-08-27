#include "Span.hpp"

Span::Span(){
	this->N = 0;
	std::cout << "Default constructor called" << std::endl;
}

Span::~Span(){}

Span::Span(const Span &source){
	*this = source;
}

Span& Span::operator=(const Span &source){
	this->N = source.N;
	this->numbers = source.numbers;
	return *this;
}

Span::Span(unsigned int N){
	this->N = N;
	this->numbers = std::vector<int>();
}

unsigned int Span::getN(){
	return this->N;
}

std::vector<int> Span::getNumbers(){
	return this->numbers;
}

void Span::addNumber(int number){
	try
	{
		if (this->numbers.size() == this->N)
			throw Span::VectorIsFullException();
		this->numbers.push_back(number);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Span::VectorIsFullException::what() const throw(){
	return "Vector is full";
}

std::ostream& operator<<(std::ostream &os, Span &span){
	os << "N: " << span.getN() << " size: " << span.getNumbers().size();
	return os;
}