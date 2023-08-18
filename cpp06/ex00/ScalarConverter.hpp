#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter& operator=(const ScalarConverter& source);
		char convertChar(std::string source);
		int convertInt(std::string source);
		float convertFloat(std::string source);
		double convertDouble(std::string source);
};

#endif