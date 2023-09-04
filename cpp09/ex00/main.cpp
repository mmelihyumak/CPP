#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

    /*if (argc != 2){
        std::cout << "Error: Invalid number of arguments" << std::endl;
        return 0;
    }*/
    try
    {
        //BitcoinExchange db;

        BitcoinExchange input(argv[1]);
        input.execdb();
       // std::cout << input << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    



    return 0;
}