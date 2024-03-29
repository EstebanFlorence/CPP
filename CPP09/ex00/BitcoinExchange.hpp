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

# define NUM_ERRORS 3

class	BitcoinExchange
{
	private:
		const std::string				databasePath;
		std::string						list;
		std::map<std::string, float>	exchangeRates;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& file);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		bool	getExchangeRates();
		bool	showExchangeValues();

		bool	isValidDate(std::string& s);
		bool	isValidAmount(const char* s, float& n);
		bool	trim(std::string& s);
		bool	bitError(int n, const std::string& s);

};

#endif