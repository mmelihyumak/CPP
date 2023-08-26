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
		char argChar = convertChar(arg);
		std::cout << "char: '" << argChar << "'" << std::endl;
		charToInt(argChar);
		charToFloat(argChar);
		charToDouble(argChar);
	}
	else if (ScalarConverter::is_int(arg) == true){
		int argInt = convertInt(arg);
		intToChar(argInt);
		std::cout << "int: " << argInt << std::endl;
		intToFloat(argInt);
		intToDouble(argInt);
	}
	else if (ScalarConverter::is_double(arg) == true)
	{
		double argDouble = convertDouble(arg);
		doubleToChar(argDouble);
		doubleToInt(argDouble);
		doubleToFloat(argDouble);
		if (argDouble / (int)argDouble == 1)
			std::cout << "double: " << argDouble << ".0" << std::endl;
		else
			std::cout << "double: " << argDouble << std::endl;
	}
	else if (ScalarConverter::is_float(arg) == true){
		float argFloat = convertFloat(arg);
		floatToChar(argFloat);
		floatToInt(argFloat);
		if (argFloat / (int)argFloat == 1)
			std::cout << "float: " << argFloat << ".0f" <<  std::endl;
		else
			std::cout << "float: " << argFloat << "f" <<  std::endl;
		floatToDouble(argFloat);
	}
	else if (!pseudoCheck(arg))
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
	unsigned int i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while(i < arg.size()){
		if (arg.find('.') != std::string::npos)
			return false;
		if (isdigit(arg[i]) == 0){
				return false;
		}
		i++;
	}
	return true;
}

bool ScalarConverter::is_float(std::string arg){
	unsigned int i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	if (arg[0] == '.')
		return false;
	while (i++ < arg.size()){
		if (arg[i] && isdigit(arg[i]) == 0){
			if (arg[i] != '.'){
				if (arg[i] != 'f'){
					return false;
				}else if (i != arg.size() - 1)
					return false;
			}
		}
	}
	int dotIndex = arg.find(".");
	if (dotIndex == -1 || (size_t)dotIndex == arg.size() - 1 || arg[arg.size() - 1] != 'f')
		return false;
	return true;
}

bool ScalarConverter::is_double(std::string arg){
	for(unsigned int i = 0; i < arg.size(); i++){
		if (arg[0] == '-' || arg[0] == '+')
			i++;
		if (isdigit(arg[i]) == 0 && (arg[0] != '-' || arg[0] != '+'))
		{
			if (arg[0] == '.')
				return false;
			if (arg[i] != '.' && arg[0] != '-' && arg[0] != '+')
				return false;
		}
	}
	int dotIndex = arg.find(".");
	if (dotIndex == -1 || (size_t)dotIndex == arg.size() - 1 || arg[arg.size() - 1] == 'f')
		return false;
	return true;
}



char ScalarConverter::convertChar(std::string arg){
	char result = static_cast<char>(arg[0]);
	return result;
}

int ScalarConverter::convertInt(std::string arg){
	int result = static_cast<int>(std::stoi(arg));
	return result;
}

float ScalarConverter::convertFloat(std::string arg){
	float result = static_cast<float>(std::stof(arg));
	return result;
}

double ScalarConverter::convertDouble(std::string arg){
	double result = static_cast<double>(std::stod(arg));
	return result;
}



void ScalarConverter::charToInt(char arg){
	int i = static_cast<int>(arg);
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::charToDouble(char arg){
	double i = static_cast<double>(arg);
	std::cout << "double: " << i << ".0" << std::endl;
}

void ScalarConverter::charToFloat(char arg){
	float i = static_cast<float>(arg);
	std::cout << "float: " << i << ".0f" << std::endl;
}



void ScalarConverter::intToChar(int arg){
	char c = static_cast<char>(arg);
	if (arg <= -1 || arg > 127)
		std::cout << "char: " <<  "Impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: " <<  "Non displayable" << std::endl;
}

void ScalarConverter::intToDouble(int arg){
	double d = static_cast<double>(arg);
	std::cout << "double: " << d << ".0" << std::endl;
}

void ScalarConverter::intToFloat(int arg){
	float f = static_cast<float>(arg);
	std::cout << "float: " << f << ".0f" << std::endl;
}



void ScalarConverter::doubleToChar(double arg){
	char c = static_cast<char>(arg);
	if (arg <= -1 || arg > 127)
		std::cout << "char: " <<  "Impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: " <<  "Non displayable" << std::endl;
}

void ScalarConverter::doubleToInt(double arg){
	int i = static_cast<int>(arg);
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::doubleToFloat(double arg){
	float f = static_cast<float>(arg);
	if (f / (int)f == 1)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}



void ScalarConverter::floatToChar(float arg){
	char c = static_cast<char>(arg);
	if (arg <= -1 || arg > 127)
		std::cout << "char: " <<  "Impossible" << std::endl;
	else if (isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: " <<  "Non displayable" << std::endl;
}

void ScalarConverter::floatToInt(float arg){
	int i = static_cast<int>(arg);
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::floatToDouble(float arg){
	double d = static_cast<double>(arg);
	if (d / int(d) == 1)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

int ScalarConverter::pseudoCheck(std::string arg){
	if (arg == "-inf" || arg == "-inff"){
		float f = std::numeric_limits<float>::infinity();
		f *= -1;
		std::cout << "char: " << "Impossible" << std::endl;
		std::cout << "int: " << "Impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		double d = std::numeric_limits<double>::infinity();
		d *= -1;
		std::cout << "double: " << d << std::endl;
	}
	else if (arg == "+inf" || arg == "+inff"){
		float f = std::numeric_limits<float>::infinity();
		std::cout << "char: " << "Impossible" << std::endl;
		std::cout << "int: " << "Impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		double d = std::numeric_limits<double>::infinity();
		std::cout << "double: " << d << std::endl;
	}
	else if (arg == "nan" || arg == "nanf"){
		std::cout << "char: " << "Impossible" << std::endl;
		std::cout << "int: " << "Impossible" << std::endl;
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "float: " << f << "f" << std::endl;
		double d = std::numeric_limits<double>::quiet_NaN();
		std::cout << "double: " << d << std::endl;
	}
	else
		return 0;
	return 1;
}
