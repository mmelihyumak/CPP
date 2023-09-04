#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <vector>
# include <map>
# include <fstream>
# include <ostream>
# include <sstream>
# include <string>


class BitcoinExchange{
    private:
        std::map<std::string, float> db;
        std::map<std::string, float> input;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange& operator=(const BitcoinExchange &source);

        void read_database(std::string filename, int flag);

        void parse_date(std::string &all_date);
        void parse_data(std::string line);
        void replace(std::string &str);

        //getters
        std::map<std::string, float>& getDb();
        std::map<std::string, float>& getInput();

        void execdb();

        class FileIsIncorrect : public std::exception{
            public:
                virtual const char* what() const throw();
        };

};

std::ostream& operator<<(std::ostream &os, BitcoinExchange &btc);

#endif