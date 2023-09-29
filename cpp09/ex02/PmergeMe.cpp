#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &source){
	*this = source;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &source){
	if (this != &source){
		this->mapValues = source.mapValues;
		this->dequeValues = source.dequeValues;
	}
	return *this;
}

void PmergeMe::setMapValues(std::map<int, int> mapValues){
	this->mapValues = mapValues;
}

void PmergeMe::setDequeValues(std::deque<int> dequeValues){
	this->dequeValues = dequeValues;
}

std::map<int, int> PmergeMe::getMapValues(){
	return this->mapValues;
}

std::deque<int> PmergeMe::getDequeValues(){
	return this->dequeValues;
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

void PmergeMe::dequeInsertionSort(int left, int right){

	for (int i = left + 1; i <= right; i++){
		int key = dequeValues[i];
		int j = i - 1;
		while (j >= left && dequeValues[j] > key){
			dequeValues[j + 1] = dequeValues[j];
			j--;
		}
		dequeValues[j + 1] = key;
	}
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

		for (size_t x = 0; x < tempValues.size(); x++){
			mapValues[j] = tempValues[x];
			j++;
		}
	}
}

void PmergeMe::dequeMergeSort(int left, int right){

	int sizeOfGroup = 5;
	int countGroup = dequeValues.size() / 5;

	if (dequeValues.size() % sizeOfGroup != 0)
		countGroup++;

	int mid = left + (right - left) / 2;

	if (right - left + 1 <= sizeOfGroup){
		dequeInsertionSort(left, right);
	}
	else{

		dequeMergeSort(left, mid);
		dequeMergeSort(mid + 1, right);

		std::deque<int> tempValues;

		int i = 0, j = left, k = mid;

		while (i < (right - j + 1) && mid + 1 <= right && left <= k){

			if (dequeValues[left] > dequeValues[mid + 1]){
				tempValues.push_back(dequeValues[mid + 1]);
				mid++;
			}
			else{
				tempValues.push_back(dequeValues[left]);
				left++;
			}
			i++;
		}

		if (mid + 1 > right){
			while (left <= k){
				tempValues.push_back(dequeValues[left]);
				left++;
				i++;
			}
		}
		else if (left > k){
			while (mid + 1 <= right){
				tempValues.push_back(dequeValues[mid + 1]);
				mid++;
				i++;
			}
		}

		for (size_t x = 0; x < tempValues.size(); x++){
			dequeValues[j] = tempValues[x];
			j++;
		}
	}
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

	std::cout << "Map: ";
	while (i <= right){
		std::cout << it->second << " ";
		i++;
		it++;
	}
	std::cout << std::endl;

}

void printDequeV2(std::deque<int> dequeValues, int left, int right){

	std::deque<int>::iterator it = dequeValues.begin();
	int i = -1;

	while (++i < left)
		it++;

	std::cout << "Deque: ";
	while (i <= right){
		std::cout << *it << " ";
		i++;
		it++;
	}
	std::cout << std::endl;
}