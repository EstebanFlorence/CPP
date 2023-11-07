#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

int	replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream	inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cerr << "Error opening " << filename << std::endl;
		return -1;
	}

	std::ofstream	outputFile(filename + ".replace");
	if (!outputFile.is_open())
	{
		std::cerr << "Error opening " << filename << ".replace" << std::endl;
		return -1;
	}

	std::string	line;
	while (std::getline(inputFile, line))
	{
		size_t	pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage " << av[0] << ": <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string	filename = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	replaceInFile(filename, s1, s2);

	return 0;
}
