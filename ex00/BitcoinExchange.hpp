/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:26 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 15:38:27 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		 class openFailed : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("openFailed");
				}
		};
		class notPositive : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: not a positive number.");
				}
		};
		class Toolarge : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: too large a number.");
				}
		};
		class DataError : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Invalid Data!");
				}
		};
};
