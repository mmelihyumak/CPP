#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &source){
	*this = source;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &source){


	return *this;
}

void PmergeMe::setMapValues(std::map<int, int> mapValues){
	this->mapValues = mapValues;
}

void PmergeMe::setListValues(std::list<int> listValues){
	this->listValues = listValues;
}

std::map<int, int> PmergeMe::getMapValues(){
	return this->mapValues;
}

std::list<int> PmergeMe::getListValues(){
	return this->listValues;
}

void PmergeMe::mapInsertionSort(int left, int right){
	for (int i = left + 1; i <= right; i++){
		int key = mapValues[i];
		int j = i - 1;
		while (j >= left && mapValues[j] > key){
			mapValues[j + 1] = mapValues[j];
			j--;
		}
		mapValues[j + 1] = key;
	}
}

void PmergeMe::listInsertionSort(int left, int right){

	for (std::list<int>::iterator it = ++listValues.begin(); it != listValues.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        
        while (j != listValues.begin() && *(--j) > key) {
            std::iter_swap(j, std::next(j, 1));
        }
        
        if (*j > key) {
            std::iter_swap(j, std::next(j, 1));
        }
    }
}

void PmergeMe::mapMergeSort(int left, int right){

	int sizeOfGroup = 5;

	std::map<int, int>::iterator it;

	int mid = left + (right - left) / 2;
	if (right - left + 1 <= sizeOfGroup){
		mapInsertionSort(0, mapValues.size() - 1);
	}
	else{
		mapMergeSort(left, mid);
		mapMergeSort(mid + 1, right);
	}
}

void PmergeMe::listMergeSort(int left, int right){

	int sizeOfGroup = 5;

	std::list<int>::iterator it;

	int mid = left + (right - left) / 2;
	if (right - left + 1 <= sizeOfGroup){
		listInsertionSort(0, listValues.size() - 1);
	}
	else{
		listMergeSort(left, mid);
		listMergeSort(mid + 1, right);
	}
}

void PmergeMe::printNumbers(){

	std::cout << "Before: ";

    std::list<int>::iterator it = this->listValues.begin();

    while (it != this->listValues.end()){
        std::cout << *it << " ";
        it++;
    }
	std::cout << std::endl;
}

const char* PmergeMe::Error::what() const throw(){
	return "Error";
}