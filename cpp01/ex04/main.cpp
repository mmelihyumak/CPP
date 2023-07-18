#include <iostream>
#include <fstream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string fileName = argv[1];
	std::string search = argv[2];
	std::string replace = argv[3];
	std::string line;
	std::string temp;
	size_t pos = 0;

	std::ifstream inFile(fileName);
	if (inFile.is_open() == 0)
	{
		std::cout << "No such file" << std::endl;
		return (1);
	}

	std::ofstream outFile(fileName + ".replace", std::ios::trunc);
	if (outFile.is_open() == 0)
	{
		std::cout << "Outfile cannot created" << std::endl;
		return (1);
	}
	
	while (std::getline(inFile, line))
	{
		pos = 0;
		temp = line;
		while ((pos = line.find(search, pos)) != std::string::npos)
		{
			temp.erase(pos, search.length());
			temp.insert(pos, replace);
			pos++;
		}
		outFile << temp << std::endl;
	}
	return (0);
}