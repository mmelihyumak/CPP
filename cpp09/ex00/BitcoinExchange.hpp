#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <fstream>
# include <ostream>
# include <sstream>
# include <string>


class BitcoinExchange{
    private:
        std::vector<std::string> db_dates;
        std::vector<float> db_values;


    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange& operator=(const BitcoinExchange &source);

        void readdb(std::string filename);
        void exec(std::string input_filename);
        bool errorcheck(std::string &line);

        bool smallerThanFirst(std::string date);
        
        void replace(std::string &str);
        bool digitcheck(std::string &str);


        class FileIsIncorrect : public std::exception{
            public:
                virtual const char* what() const throw();
        };

};

#endif