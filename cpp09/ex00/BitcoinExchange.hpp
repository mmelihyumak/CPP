#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <vector>
# include <fstream>
# include <ostream>
# include <sstream>
# include <string>
# include "Date.hpp"


class BitcoinExchange{
    private:
        std::map<t_date, float> db;
        std::map<t_date, float> in;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange& operator=(const BitcoinExchange &source);

        void readfile(std::string filename);

        void replace(std::string &str);
        t_date fill_t_date(std::string &key);

        class FileIsIncorrect : public std::exception{
            public:
                virtual const char* what() const throw();
        };

};

#endif