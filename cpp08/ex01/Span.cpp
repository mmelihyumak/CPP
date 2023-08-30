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

void Span::addNumbers(int number){
	try
	{
		if (this->numbers.size() == this->N)
			throw Span::VectorIsFullException();
		srand(time(NULL));
		for (int i = 0; i < number; i++){
			if (i % 2 == 1)
				this->numbers.push_back((rand() % 100000) * -1);
			else
				this->numbers.push_back(rand() % 100000);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

bool Span::comp(int a, int b){
	return a < b;
}

int Span::shortestSpan(){
	try
	{
		if (this->numbers.size() <= 1)
			throw Span::VectorIsEmptyException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
	
	std::vector<int> temp = this->numbers;
	std::sort(temp.begin(), temp.end());

	int min = temp[1] - temp[0];

	for (int i = 0; i < (int)temp.size() - 1; i++){
		if (min > temp[i + 1] - temp[i])
			min = temp[i + 1] - temp[i];
	}
	return min;
}

int Span::longestSpan(){
	try
	{
		if (this->numbers.size() <= 1)
			throw Span::VectorIsEmptyException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
	
	std::vector<int>::iterator min = std::min_element(this->numbers.begin(), this->numbers.end());
	std::vector<int>::iterator max = std::max_element(this->numbers.begin(), this->numbers.end());

	return *max - *min;
}


const char* Span::VectorIsFullException::what() const throw(){
	return "Vector is full";
}

const char * Span::VectorIsEmptyException::what() const throw(){
	return "No span can be found";
}

std::ostream& operator<<(std::ostream &os, Span &span){
	os << "N: " << span.getN() << " size: " << span.getNumbers().size();
	return os;
}