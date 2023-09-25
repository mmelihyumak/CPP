#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <map>
# include <sstream>
# include <ctime>
# include <algorithm>
# include <iterator>

class PmergeMe{

	private:
		std::map<int, int> mapValues;
		std::list<int> listValues;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &source);
		PmergeMe& operator=(const PmergeMe &source);

		void setMapValues(std::map<int, int> mapValues);
		void setListValues(std::list<int> listValues);

		std::map<int, int> getMapValues();
		std::list<int> getListValues();

		void mapInsertionSort(int left, int right);
		
		void listInsertionSort(int left, int right);

		void mapMergeSort(int left, int right);
		void listMergeSort(int left, int right);
	
		void printNumbers();

		class Error : public std::exception{
			public:
				const char* what() const throw();
		};

};

//Silinecekler!!!
void printMapV2(std::map<int, int> mapValues, int left, int right);


#endif
