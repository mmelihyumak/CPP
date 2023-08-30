#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <fstream>


class BitcoinExchange{
    private:
        std::vector<int> _years;
        std::vector<int> _months;
        std::vector<int> _days;
        std::vector<float> _values;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange& operator=(const BitcoinExchange &source);

        void parse_data(std::string line);

        /* Setters
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setValue(float);*/

};

#endif