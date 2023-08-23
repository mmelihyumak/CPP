#include "easyfind.hpp"

int main(){

	std::list<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	numbers.push_back(40);
	numbers.push_back(80);

	std::cout << easyfind(numbers, 30) << std::endl;

	std::vector<int> intVector;
	intVector.push_back(10);
	intVector.push_back(20);
	intVector.push_back(40);
	intVector.push_back(30);
	intVector.push_back(50);
	std::cout << easyfind(intVector, 30) << std::endl;


	std::set<int> intSet;

	intSet.insert(20);
	intSet.insert(40);
	intSet.insert(30);
	intSet.insert(50);
	intSet.insert(10);
	std::cout << easyfind(intSet, 30) << std::endl;



	return 0;
}