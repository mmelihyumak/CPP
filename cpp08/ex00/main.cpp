#include "easyfind.hpp"
#include <vector>
#include <set>
#include <list>
#include <deque>

int main(){

	try
	{
		std::list<int> numbers;

		numbers.push_back(10);
		numbers.push_back(20);
		numbers.push_back(30);
		numbers.push_back(40);
		numbers.push_back(125);
		std::cout << *(easyfind(numbers, 125)) << std::endl;

		std::vector<int> intVector;

		intVector.push_back(10);
		intVector.push_back(20);
		intVector.push_back(40);
		intVector.push_back(30);
		intVector.push_back(50);
		std::cout << *(easyfind(intVector, 20)) << std::endl;

		std::deque<int> intDeque;
		intVector.push_back(10);
		intVector.push_back(20);
		intVector.push_back(40);
		intVector.push_back(30);
		intVector.push_back(50);
		std::cout << *(easyfind(numbers, 20)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}