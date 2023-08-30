#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span{
	private:
		unsigned int N;
		std::vector<int> numbers;

	public:
		Span();
		~Span();
		Span(const Span &source);
		Span& operator=(const Span &source);
		Span(unsigned int N);
		unsigned int getN();
		std::vector<int> getNumbers();

		void addNumber(int number);
		void addNumbers(int number);

		int shortestSpan();
		int longestSpan();
		static bool comp(int a, int b); //bunu kontrol et

		class VectorIsFullException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class VectorIsEmptyException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, Span &span);

#endif