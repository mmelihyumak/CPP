#include "iter.hpp"

int main()
{
    {
        int array[3] = {1, 2, 3};
        iter(array, 3, print);
    }

    {
        std::string array[4] = {"mustafa", "melih", "yumak", "abcd"};
        iter(array, 6, print);
    }
    return 0;
}