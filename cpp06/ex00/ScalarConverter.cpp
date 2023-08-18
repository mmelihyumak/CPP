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

char ScalarConverter::convertChar(std::string source){
	return 0;
}

int ScalarConverter::convertInt(std::string source){
	
}

float ScalarConverter::convertFloat(std::string source){
	
}

double ScalarConverter::convertDouble(std::string source){
	
}