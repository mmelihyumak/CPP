#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

   

    
    try
    {
        BitcoinExchange btc(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}