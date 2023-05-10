#pragma once
#include <iostream>
#include <fstream>
#include <sstream> 
#include <map>

class BitcoinExchange
{
	private:

		std::map<std::string, float> _exchangeRates;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string& data_name);
		BitcoinExchange(const BitcoinExchange& Bit);
		virtual ~BitcoinExchange(void);

		BitcoinExchange&	operator=(const BitcoinExchange& Bit);

		float getExchangeRate(const std::string& date, float value) const;
		bool	_checkdate(const std::string& dateStr) const;
};
