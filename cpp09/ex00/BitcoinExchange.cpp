#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename){

    read_database("data.csv", 0);
    read_database(filename, 1);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &source){
    if (this != &source){
        this->db = source.db;
        this->input = source.input;
    }
    return *this;
}

// Getters
std::map<std::string, float>& BitcoinExchange::getDb(){
    return this->db;
}

std::map<std::string, float>& BitcoinExchange::getInput(){
    return this->input;
}

void BitcoinExchange::read_database(std::string filename, int flag){

    std::string line;
    std::string key;
    std::string value;
    std::ifstream data(filename);
    char schar;
    std::map<std::string, float>::iterator ite;

    if (data.is_open() != true)
        throw BitcoinExchange::FileIsIncorrect();

    while (getline(data, line)){
        replace(line);
        std::stringstream ss(line);
        getline(ss, key, ',');
        getline(ss, value, ',');
        if (line != "date,exchange_rate" && value != "value"){
            if (flag == 0)
                db[key] = std::stof(value);
            else
                input[key] = std::stof(value);
        }
    }
}

void BitcoinExchange::execdb(){

    std::map<std::string, float>::iterator in_begin = input.begin();
    std::map<std::string, float>::iterator in_end = input.end();
    
    std::map<std::string, float>::iterator db_begin = db.begin();
    std::map<std::string, float>::iterator db_end = db.end(); 

    while (in_begin != in_end){
        while (db_begin != db_end){
            if (in_begin->first == db_begin->first){
                std::cout << in_begin->first << " => " << in_begin->second << " = " << (in_begin->second * db_begin->second) << std::endl;
                break ;
            }
            
            db_begin++;
        }
        in_begin++;
    }
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

const char* BitcoinExchange::FileIsIncorrect::what() const throw(){
    return "Error: Invalid file format";
}

std::ostream& operator<<(std::ostream &os, BitcoinExchange &btc){

    std::map<std::string, float>::iterator line_begin = btc.getDb().begin();
    
    while (line_begin != btc.getDb().end()){
        std::cout << "Key: " << line_begin->first << " Value: " << line_begin->second << std::endl;
        line_begin++;
    }

    return os;
}

