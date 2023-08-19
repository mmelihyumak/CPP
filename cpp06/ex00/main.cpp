#include "ScalarConverter.hpp"

int main(int argc, char **argv){

    if (argc != 2)
        std::cerr << "Invalid number of arguments!" << std::endl;
    else
        ScalarConverter::convert(argv[1]);
    return 0;
}