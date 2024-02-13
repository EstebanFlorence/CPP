#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& file)
: databasePath("./data.csv"), list(file)
{
	// loadDatabase(file);
	// list = file;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
: list(copy.list), exchangeRates(copy.exchangeRates)
{}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->list = other.list;
		this->exchangeRates = other.exchangeRates;
	}

	return *this;
}


void	BitcoinExchange::loadDatabase(const std::string& file)
{
	std::ifstream	databaseFile(databasePath);
	std::ifstream	inputFile(file.c_str());

	if (!databaseFile)
		std::runtime_error("Error: missing database file");
	else if (!inputFile)
		std::runtime_error("Error: missing input file");

	databaseFile.close();
	inputFile.close();
}

bool	BitcoinExchange::parseDatabase()
{
	std::ifstream	databaseFile(databasePath);
	std::string		line;

	std::getline(databaseFile, line);	// Skip first line
	while (std::getline(databaseFile, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		float				price;

		if (std::getline(iss, date, ',') && isValidDate(date) && iss >> price)	// Check also price?
		{
			exchangeRates[date] = price;
		}
		else
		{
			std::cerr << "Error: bad input ==> " << line << std::endl;
			return false;
		}
	}

	return true;
}

bool	BitcoinExchange::parseInputFile()
{
	std::ifstream	inputFile(list);
	std::string		line;

	std::getline(inputFile, line);	// Skip first line
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;

		std::istringstream	iss(line);
		std::string			date;
		std::string			sValue;
		float				fValue(0);

		if (std::getline(iss, date, '|') && isValidDate(date) && std::getline(iss, sValue))
		{
			if (!trim(sValue) || !isValidAmount(sValue.c_str(), fValue))
			{
				bitError(1, line);
				continue;
			}
			std::map<std::string, float>::const_iterator	it = exchangeRates.lower_bound(date);
			std::cout << it->first << std::endl;
			if (it != exchangeRates.end())
				std::cout << date << " => " << fValue << " = " << fValue * it->second << std::endl;
		}
		else
		{
			bitError(1, line);
			continue;
		}
	}

	return true;
}

void	BitcoinExchange::displayPrice()
{

}


bool	BitcoinExchange::isValidDate(std::string& s)
{
	if (!trim(s))
		return false;

	struct tm	tm = {};
	if (!strptime(s.c_str(), "%Y-%m-%d", &tm))
		return false;
	time_t	time = mktime(&tm);

	struct tm	startTime = {};
	startTime.tm_year = 2009 - 1900;
	startTime.tm_mon = 0;
	startTime.tm_mday = 2;
	time_t	start = mktime(&startTime);

	struct tm	endTime = {};
	endTime.tm_year = 2022 - 1900;
	endTime.tm_mon = 3;
	endTime.tm_mday = 29;
	time_t	end = mktime(&endTime);

	return (start <= time && time <= end);
}

bool	BitcoinExchange::isValidAmount(const char* s, float& n)
{
	char*	endPtr = nullptr;

	n = std::strtof(s, &endPtr);
	if (endPtr == s || *endPtr != 0)
		return bitError(1, s);
	if (n < 0)
		return bitError(2, "");
	else if (n > 100000)
		return bitError(3, "");

	return true;

	// std::stringstream	ss(s);
	// double				value(0);

	// ss >> value;

	// return ss.good();
}

bool	BitcoinExchange::trim(std::string& s)
{
	if (s.empty())
		return false;

	s.erase(0, s.find_first_not_of(" \t\r\n"));
	s.erase(s.find_last_not_of(" \t\r\n") + 1);

	return true;
}

bool	BitcoinExchange::bitError(int n, const std::string& s)
{
	switch (n)
	{
		case 1:
		std::cerr << "Error: bad input => " << s << std::endl;
		break;

		case 2:
		std::cerr << "Error: not a positive number." << std::endl;
		break;

		case 3:
		std::cerr << "Error: too large a number." << std::endl;
		break;

		default:
			break;
	}

	return false;
}
