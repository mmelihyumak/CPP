#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& source){
	*this = source;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& source){
	(void)source;
	return *this;
}

void ScalarConverter::convert(std::string arg){
	if (ScalarConverter::is_char(arg) == true){

		std::cout << "The arg is a char!" << std::endl;
	}
	else if (ScalarConverter::is_int(arg) == true)
		std::cout << "The arg is an integer!" << std::endl;
	else if (ScalarConverter::is_double(arg) == true)
		std::cout << "The arg is a double!" << std::endl;
	else if (ScalarConverter::is_float(arg) == true)
		std::cout << "The arg is a float!" << std::endl;
	else
		std::cerr << "Invalid argument type!" << std::endl;

	
}

bool ScalarConverter::is_char(std::string arg){
	if (arg.size() != 1)
		return false;
	if (isdigit(arg[0]) != 0)
		return false;
	return true;
}

bool ScalarConverter::is_int(std::string arg){
	for(int i = 0; i < arg.size(); i++){
		if (isdigit(arg[i]) == 0)
			return false;
	}
	return true;
}

bool ScalarConverter::is_float(std::string arg){
	for(int i = 0; i < arg.size(); i++){
		if (isdigit(arg[i]) == 0)
			if (arg[i] != '.'){
				if (arg[i] != 'f'){
					return false;
				}else if (i != arg.size() - 1)
					return false;
			}
	}
	int dotIndex = arg.find(".");
	std::cout << "Dot index-> " << dotIndex << std::endl;
	if (dotIndex == -1 || dotIndex == arg.size() - 1 || arg[arg.size() - 1] != 'f')
		return false;
	return true;
}

bool ScalarConverter::is_double(std::string arg){
	for(int i = 0; i < arg.size(); i++){
		if (isdigit(arg[i]) == 0)
			if (arg[i] != '.')
				return false;
	}
	int dotIndex = arg.find(".");
	std::cout << "Dot index-> " << dotIndex << std::endl;
	if (dotIndex == -1 || dotIndex == arg.size() - 1 || arg[arg.size() - 1] == 'f')
		return false;
	return true;
}

// Dönüşüm methodları yazılacak!

char ScalarConverter::convertChar(std::string arg){
	char result = arg[0];
	return result;
}

int ScalarConverter::convertInt(std::string arg){
	int result = std::stoi(arg);
	return result;
}

float ScalarConverter::convertFloat(std::string arg){
	return 0;
}

double ScalarConverter::convertDouble(std::string arg){
	return 0;
}