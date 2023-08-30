#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::ifstream file("data.csv");
    if (!file){
        std::cerr << "Error: could not open file" << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line);
    std::getline(file, line);
    parse_data(line);
    //std::cout << line << std::endl;
    file.close();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &source){
    if (this != &source){
        this->_years = source._years;
        this->_months = source._months;
        this->_days = source._days;
        this->_years = source._years;
    }
    return *this;
}

void BitcoinExchange::parse_data(std::string line){
    this->_years.push_back(std::stoi(line));
    std::cout << "year: " << this->_years[0] << std::endl;

    this->_months.push_back(std::stoi(line.substr(5, 2)));
    std::cout << "month: " << this->_months[0] << std::endl;

    this->_days.push_back(std::stoi(line.substr(8, 2)));
    std::cout << "days: " << this->_days[0] << std::endl;
}



