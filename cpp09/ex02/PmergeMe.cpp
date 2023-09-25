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

void printMap(std::map<int, int> maps, int mode){

    if (mode == 0)
        std::cout << "Before: ";
    else if (mode == 1)
        std::cout << "After: ";

    std::map<int, int>::iterator it = maps.begin();

    while (it != maps.end()){
        std::cout << it->second << " ";
        it++;
    }
        std::cout << std::endl;
}

void PmergeMe::mapMergeSort(int left, int right){

	int sizeOfGroup = 5;
	int countGroup = mapValues.size() / 5;

	if (mapValues.size() % sizeOfGroup != 0)
		countGroup++;

	int mid = left + (right - left) / 2;

	if (right - left + 1 <= sizeOfGroup){
		mapInsertionSort(left, right);
	}
	else{

		mapMergeSort(left, mid);
		mapMergeSort(mid + 1, right);


		std::map<int, int> tempValues;

		int i = 0, j = left, k = mid;

		while (i < (right - j + 1) && mid + 1 <= right && left <= k){

			if (mapValues[left] > mapValues[mid + 1]){
				tempValues[i] = mapValues[mid + 1];
				mid++;
			}
			else{
				tempValues[i] = mapValues[left];
				left++;
			}
			i++;
		}
		if (mid + 1 > right){
			while (left <= k){
				tempValues[i] = mapValues[left];
				left++;
				i++;
			}
		}
		else if (left > k){
			while (mid + 1 <= right){
				tempValues[i] = mapValues[mid + 1];
				mid++;
				i++;
			}
		}

		for (int x = 0; x < tempValues.size(); x++){
			mapValues[j] = tempValues[x];
			j++;
		}
	}
}

void PmergeMe::listMergeSort(int left, int right){

	int sizeOfGroup = 5;

	int mid = left + (right - left) / 2;
	if (right - left + 1 <= sizeOfGroup){
		listInsertionSort(0, right);
	}
	else{
		listMergeSort(left, mid);
		listMergeSort(mid + 1, right);

		std::list<int> tempValues;
		std::list<int>::iterator tempIt = tempValues.begin();

		int i = 0, j = left, k = mid;

		while (i < (right - j + 1) && mid + 1 <= right && left <= k){

			if (mapValues[left] > mapValues[mid + 1]){
				*tempIt = mapValues[mid + 1];
				mid++;
			}
			else{
				*tempIt = mapValues[left];
				left++;
			}
			tempIt++;
			i++;
		}

		if (mid + 1 > right){
			while (left <= k){
				*tempIt = mapValues[left];
				left++;
				i++;
			}
		}
		else if (left > k){
			while (mid + 1 <= right){
				*tempIt = mapValues[mid + 1];
				mid++;
				i++;
			}
		}

		tempIt = tempValues.begin();
		std::list<int>::iterator it = listValues.begin();

		for (int x = 0; x < j; x++){
			it++;
		}

		for (int x = 0; x < tempValues.size(); x++){
			*it = *tempIt;
			j++;
			it++;
			tempIt++;
		}
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





//Silinecekler

void printMapV2(std::map<int, int> mapValues, int left, int right){

	std::map<int, int>::iterator it = mapValues.begin();
	int i = -1;

	while (++i < left)
		it++;

	while (i <= right){
		std::cout << it->second << " ";
		i++;
		it++;
	}
	std::cout << std::endl;

}