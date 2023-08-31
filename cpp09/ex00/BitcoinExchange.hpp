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
        std::vector<std::string> _lines;
        std::vector<std::string> _years;
        std::vector<std::string> _months;
        std::vector<std::string> _days;
        std::vector<float> _values;
    
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange& operator=(const BitcoinExchange &source);

        void parse_date(std::string &all_date);
        void parse_data(std::string line);
        void replace(std::string &str);

        //getters
        std::vector<std::string>& getYears();
        std::vector<std::string>& getMonths();
        std::vector<std::string>& getDays();
        std::vector<float>& getValues();
        std::vector<std::string>& getLines();


        class FileIsIncorrect : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        /* Setters
        void setYear(int);
        void setMonth(int);
        void setDay(int);
        void setValue(float);*/

};

std::ostream& operator<<(std::ostream &os, BitcoinExchange &btc);

#endif