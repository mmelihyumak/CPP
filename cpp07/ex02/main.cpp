#include "Array.hpp"

int main(){


    //int *arr = intArray->getArr();
    //for (int i = 0; i < 4; i++)
      //  std::cout << arr[i] << std::endl;

    try
    {
        Array<int> intArray(4);
        std::cout << intArray[4] << std::endl;
    }
    catch(Array<int>::OutOfBoundsException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    //int *arr2 = intArray2->getArr();
    //for (int i = 0; i < 4; i++)
      //  std::cout << arr2[i] << std::endl;

    return 0;
}