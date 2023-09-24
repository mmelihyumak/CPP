#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

    if (argc != 2){
        std::cout << "Error" << std::endl;
        exit(0);
    }
    
    try
    {
        BitcoinExchange btc;

        btc.exec(argv[1]);
    }
    catch(const std::exception& e)
    {
        //std::cout << e.what() << '\n';
    }

    return 0;
}