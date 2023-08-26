#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char **argv) {
    
    if (argc != 2){
        std::cerr << "Invalid number of arguments!" << std::endl;
    }else{
        try
        {
            ScalarConverter::convert(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
