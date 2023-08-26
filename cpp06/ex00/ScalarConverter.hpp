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

		static bool is_char(std::string arg);
		static bool is_int(std::string arg);
		static bool is_float(std::string arg);
		static bool is_double(std::string arg);

		static char convertChar(std::string arg);
		static int convertInt(std::string arg);
		static float convertFloat(std::string arg);
		static double convertDouble(std::string arg);

		static void charToInt(char arg);
		static void charToDouble(char arg);
		static void charToFloat(char arg);

		static void intToChar(int arg);
		static void intToDouble(int arg);
		static void intToFloat(int arg);

		static void doubleToChar(double arg);
		static void doubleToInt(double arg);
		static void doubleToFloat(double arg);

		static void floatToChar(float arg);
		static void floatToInt(float arg);
		static void floatToDouble(float arg);

		static void pseudoCheck(std::string arg); // burda kaldın
};

#endif