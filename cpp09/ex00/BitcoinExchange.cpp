#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){

    std::string format;
    std::string temp;
    std::string line;
    std::ifstream file("data.csv");

    if (!file.is_open()){
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }
    
    while (std::getline(file, line)){
        this->_lines.push_back(line);
    }


   // std::getline(file, format);
    
    std::cout << format << std::endl;
    if (format != "date,exchange_rate"){
        throw BitcoinExchange::FileIsIncorrect();
    }

    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        parse_date(temp);
        std::getline(ss, temp, ',');
        this->_values.push_back(std::stof(temp)); // try-catch
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string filename){

    std::string format;
    std::string temp;
    std::string line;
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cout << "Error: could not open file" << std::endl;
        return ;
    }

    std::getline(file, format);
    if (format != "date | value"){
        throw BitcoinExchange::FileIsIncorrect();
    }


    while (std::getline(file, line)){
        
        replace(line);
        std::cout << "line: " << line << std::endl;
        std::stringstream ss(line);
        std::getline(ss, temp, ',');
        parse_date(temp);
        std::getline(ss, temp, ',');
        this->_values.push_back(std::stof(temp)); // try-catch
    }
    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &source){
    if (this != &source){
        this->_years = source._years;
        this->_months = source._months;
        this->_days = source._days;
        this->_values = source._values;
    }
    return *this;
}


// Getters
std::vector<std::string>& BitcoinExchange::getYears(){
    return this->_years;
}

std::vector<std::string>& BitcoinExchange::getMonths(){
    return this->_months;
}

std::vector<std::string>& BitcoinExchange::getDays(){
    return this->_days;
}

std::vector<float>& BitcoinExchange::getValues(){
    return this->_values;
}

std::vector<std::string>& BitcoinExchange::getLines(){
    return this->_lines;
}


void BitcoinExchange::parse_date(std::string &all_date){

    
    std::stringstream ss(all_date);
    std::string temp;

    std::getline(ss, temp, '-');
    this->_years.push_back(temp);

    std::getline(ss, temp, '-');
    this->_months.push_back(temp);

    std::getline(ss, temp, '-');
    this->_days.push_back(temp);

    //std::cout << "year: " << _years[0] << " months: " << _months[0] << " days: " << _days[0] << std::endl;
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

    std::vector<std::string>::iterator year_begin = btc.getYears().begin();
    std::vector<std::string>::iterator month_begin = btc.getMonths().begin();
    std::vector<std::string>::iterator day_begin = btc.getDays().begin();
    std::vector<float>::iterator value_begin = btc.getValues().begin();
    
    while (year_begin < btc.getYears().end()){
        std::cout << "year: " << *year_begin << " months: " << *month_begin << " days: " << *day_begin << " value: " << *value_begin << std::endl;
        year_begin++;
        month_begin++;
        day_begin++;
        value_begin++;
    }

    return os;
}

