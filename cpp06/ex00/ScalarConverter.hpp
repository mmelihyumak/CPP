#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& source);
		ScalarConverter& operator=(const ScalarConverter& source);

		static void convert(std::string arg);

		static void execConvert(int i);

		static bool is_char(std::string arg);
		static bool is_int(std::string arg);
		static bool is_float(std::string arg);
		static bool is_double(std::string arg);

		static char convertChar(std::string arg);
		static int convertInt(std::string arg);
		static float convertFloat(std::string arg);
		static double convertDouble(std::string arg);
};

#endif