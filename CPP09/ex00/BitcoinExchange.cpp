#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
: databasePath("./data.csv"), list(inputFile)
{
	// loadDatabase(inputFile);
	// list = inputFile;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
: list(copy.list), exchangeRate(copy.exchangeRate)
{}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->list = other.list;
		this->exchangeRate = other.exchangeRate;
	}

	return *this;
}


void	BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream	databaseFile(databasePath);
	std::ifstream	inputFile(filename.c_str());

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

	while (std::getline(databaseFile, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		float				price;

		if (std::getline(iss, date, ',') && isValidDate(date) && iss >> price)	// Check also price?
			exchangeRate[date] = price;
		else
		{
			std::cerr << "Error: in database ==> " << line << std::endl;
			return false;
		}
	}

	return true;
}

bool	BitcoinExchange::parseInputFile()
{
	std::ifstream	inputFile(list);
	std::string		line;

	while (std::getline(inputFile, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		float				value;

		if (std::getline(iss, date, '|') && isValidDate(date) && iss >> value)	// Check also price?
		{
			exchangeRate[date] = value;
		}
	}

	return true;
}

void	BitcoinExchange::displayPrice()
{

}


bool	BitcoinExchange::isValidDate(const std::string& s)
{
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

	return (time >= start && time <= end);
}
