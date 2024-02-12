#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <iomanip>
# include <map>
# include <algorithm>
# include <ctime>

class	BitcoinExchange
{
	private:
		const std::string				databasePath;
		std::string						list;
		std::map<std::string, float>	exchangeRate;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& inputFile);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	loadDatabase(const std::string& filename);
		bool	parseDatabase();
		bool	parseInputFile();
		void	displayPrice();

		bool	isValidDate(const std::string& s);
		bool	extractDate(std::istringstream iss, int& y, int& m, int& d);


};

#endif