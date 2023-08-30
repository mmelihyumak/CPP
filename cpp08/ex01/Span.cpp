#include "Span.hpp"

Span::Span(){
	this->N = 0;
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
		if (number > this->N)
			throw Span::VectorIsFullException();
		this->numbers.resize(number);
		std::vector<int>::iterator begin;
		srand(time(NULL));
		for (begin = this->numbers.begin(); begin < this->numbers.end(); begin++){
			*begin = (rand() % 100) + number;
			number--;
			if (rand() % 2 == 1)
				*begin *= -1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::shortestSpan(){
	if (this->numbers.size() <= 1)
		throw Span::VectorIsEmptyException();
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
	if (this->numbers.size() <= 1)
		throw Span::VectorIsEmptyException();

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