/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:24 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 22:59:08 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const std::string& data_name)
{
	std::ifstream file(data_name.c_str());
	if (!file.is_open())
		throw openFailed();
	std::string line;
	while (std::getline(file, line))
	{
		std::stringstream tmp(line);
		std::string date;
		float price;
		if (std::getline(tmp, date, ',') && tmp >> price)
			_exchangeRates[date] = price;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& Bit)
{
	*this = Bit;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& Bit)
{
	if (this != &Bit)
		this->_exchangeRates = Bit._exchangeRates;
	return (*this);
}
bool	BitcoinExchange::_checkdate(const std::string& Date) const
{
	int year, month, day;
	char separator;
	std::istringstream tmp(Date);
	unsigned long t;
	t = 0;
	t = std::count(Date.begin(), Date.end(), '-');
	if( t != 2)
		return(0);
	tmp >> year >> separator >> month >> separator >> day;
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return (0);
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return (0);
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return (0);
		}
		else
		{
			if (day > 28)
				return (0);
		}
	}
	return (1);
}
float BitcoinExchange::getExchangeRate(const std::string& date, float value) const
{
	if (value < 0)
		throw notPositive();
	if (value > 1000)
		throw Toolarge();
	if (_checkdate(date) == 0)
		throw DataError();
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it == _exchangeRates.end())
	{
		it = _exchangeRates.upper_bound(date);
		if (it == _exchangeRates.begin())
			throw DataError();
		--it;
	}
	return (it->second);
}
