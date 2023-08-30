#include <iostream>
#include "Array.hpp"

template <typename T>
void fillArray(Array<T> &array, unsigned int size){
    for (unsigned int i = 0; i < size; i++)
        array[i] = (int)i;
}

template <typename T>
void printArray(Array<T> &array, unsigned int size){
    for (unsigned int i = 0; i < size; i++)
        std::cout << array[i] << ", ";
    std::cout << std::endl;
}

#define MAX_VAL 750
int main(int, char**)
{

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}