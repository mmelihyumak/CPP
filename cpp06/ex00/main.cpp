#include "ScalarConverter.hpp"

/*int main(int argc, char **argv){

    if (argc != 2)
        std::cerr << "Invalid number of arguments!" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    return 0;
}*/

#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    try
    {
        /* code */
        ScalarConverter::convert(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
