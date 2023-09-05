#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &source){
    if (this != &source){
        this->db = source.db;
        this->in = source.in;
    }
    return *this;
}

BitcoinExchange::BitcoinExchange(std::string filename){
    readfile(filename);
}

void BitcoinExchange::readfile(std::string filename){

    std::ifstream file(filename);
    if (file.is_open() == false){
        std::cout << "File can not open!" << std::endl;
        exit(0);
    }

    std::string line;
    getline(file, line);
    std::cout << "line: " << line << std::endl;

    getline(file, line);
    std::cout << "line: " << line << std::endl;
    replace(line);

    
    std::stringstream ss(line);
    std::string key;
    getline(ss, key, ',');
    t_date date = fill_t_date(key);

    getline(ss, key, ',');
    this->in[date] = std::stof(key);
    std::cout << "value: " << this->in[date] << std::endl;

}

t_date BitcoinExchange::fill_t_date(std::string &key){
    t_date date;

    std::cout << "key: " << key << std::endl;

    std::stringstream ss2(key);
    std::string number;
    getline(ss2, number, '-');
    date.year = std::stoi(number);

    getline(ss2, number, '-');
    date.month = std::stoi(number);

    getline(ss2, number, '-');
    date.day = std::stoi(number);

    std::cout << "year: " << date.year << " month: " << date.month << " day: " << date.day << std::endl;
    return date;
}

void BitcoinExchange::replace(std::string &str){

    int pos;
    std::string temp;
    std::string search = " | ";
    std::string rplc = ",";

    pos = 0;
	temp = str;
	while ((pos = str.find(search, pos)) != std::string::npos)
	{
    	temp.erase(pos, search.length());
		temp.insert(pos, rplc);
		pos++;
	}
	str = temp;
}