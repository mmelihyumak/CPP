#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    readdb("data.csv");
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source){
    *this = source;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &source){
    if (this != &source){
        //burayı düzelt;
    }
    return *this;
}

void BitcoinExchange::readdb(std::string filename){

    std::ifstream file(filename);
    if (file.is_open() == false){
        std::cout << "File can not open!" << std::endl;
        exit(0);
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)){
        std::stringstream ss(line);
        std::string key;
        getline(ss, key, ',');
        db_dates.push_back(key);
        getline(ss, key, ',');
        db_values.push_back(std::stof(key));
    }
}

void BitcoinExchange::exec(std::string input_filename){

    std::ifstream file(input_filename);

    if (file.is_open() == false){
        std::cout << "Error: No such file\n";
    }

    std::string line;
    getline(file, line);
    if (line != "date | value")
    {
        std::cout << "Error: File format is invalid\n";
        exit(0);
    }

    while (getline(file, line)){

        if (line.find(",", 0) != std::string::npos)
            std::cout << "Error: Invalid inputt\n";
        replace(line);
        if (errorcheck(line) == false)
            continue;

        std::stringstream ss(line);
        std::string date;
        getline(ss, date, ',');
        std::string value;
        getline(ss, value, ',');
        float vl = std::stof(value);

        std::vector<std::string>::iterator date_begin = db_dates.begin();
        std::vector<float>::iterator value_begin = db_values.begin();

        int flag = 0;
        while (date_begin < db_dates.end() && *date_begin <= date){
            if (date == *date_begin){
                std::cout << date << " => " << vl << " = " << vl * *value_begin << std::endl;
                flag = 1;
                break ;
            }
            date_begin++;
            value_begin++;
        }
        if (flag == 0){
            date_begin--;
            value_begin--;
            std::cout << date << " => " << vl << " = " << vl * *value_begin << std::endl;
        }
    }

}

bool BitcoinExchange::errorcheck(std::string &line){
    int i = line.find(",", 0);
    if (isdigit(line[i - 1]) == false || (isdigit(line[i + 1]) == false && line[i + 1] != '-')){
        std::cout << "Error: invalid format" << " => " << line << std::endl;
        return false;
    }
    else if (isdigit(line[i + 1]) == false && line[i + 1] == '-'){
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }
    std::stringstream ss(line);
    std::string date;
    getline(ss, date, ',');
    std::stringstream ssdate(date);
    std::string year;
    getline(ssdate, year, '-');
    std::string month;
    getline(ssdate, month, '-');
    std::string day;
    getline(ssdate, day, '-');
    std::string value;
    getline(ss, value, ',');

    if (isdigit(line[0]) == false){
        std::cout << "Error: bad input" << " =>1 " << date << std::endl;
        return false;
    }
    if (!digitcheck(year) || !digitcheck(month) || !digitcheck(day)){
        std::cout << "Error: bad input" << " =>1 " << date << std::endl;
        return false;
    }
    for (int x = 0; value[x]; x++){
        if (isdigit(value[x]) == false){
            if (x == 0 && value[x] == '-'){
                std::cout << "Error: not a positive number" << std::endl;
                return false;
            }
            else if (x != 0 && value[x] == '.')
                continue;
            else{
                std::cout << "Error: bad input" << " =>2 " << date << std::endl;
                return false;
            }
        }
    }
    float vl = std::stof(value);
    if (vl > 1000){
        std::cout << "Error: too large a number" << std::endl;
        return false;
    }
    else if (vl < 0){
        std::cout << "Error: not a positive number" << std::endl;
        return false;
    }

    if (month > "12" || month <= "00" ||  day > "31" || day <= "00"){
        std::cout << "Error: bad input" << " =>3 " << date << std::endl;
        return false;
    }

    if (day == "29" && month == "02" && std::stoi(year) % 4 != 0)
    {
        std::cout << "Error: bad input" << " =>3 " << date << std::endl;
        return false;
    }

    if (month == "02" && day >= "30"){
        std::cout << "Error: bad input" << " =>3 " << date << std::endl;
        return false;
    }

    if (month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12"){
        if (day > "31"){
            std::cout << "Error: bad input" << " =>3 " << date << std::endl;
            return false;
        }
    }else{
        if (day > "30"){
            std::cout << "Error: bad input" << " =>3 " << date << std::endl;
            return false;
        }
    }
    return true;
}

bool BitcoinExchange::digitcheck(std::string &str){
    for (int i = 0; str[i]; i++)
    {
        if (isdigit(str[i]) == false){
            return false;
        }
    }
    return true;
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