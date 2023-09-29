#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <map>
# include <deque>
# include <sstream>
# include <ctime>

class PmergeMe{

	private:
		std::map<int, int> mapValues;
		std::deque<int> dequeValues;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &source);
		PmergeMe& operator=(const PmergeMe &source);

		void setMapValues(std::map<int, int> mapValues);
		void setDequeValues(std::deque<int> dequeValues);

		std::map<int, int> getMapValues();
		std::deque<int> getDequeValues();

		void mapInsertionSort(int left, int right);
		void dequeInsertionSort(int left, int right);
		

		void mapMergeSort(int left, int right);
		void dequeMergeSort(int left, int right);
	
		void printNumbers();

		class Error : public std::exception{
			public:
				const char* what() const throw();
		};

};

//Silinecekler!!!
void printMapV2(std::map<int, int> mapValues, int left, int right);
void printDequeV2(std::deque<int> dequeValues, int left, int right);

#endif
