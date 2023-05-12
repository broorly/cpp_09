/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:29 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 23:17:02 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include"BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR: " << argv[0] << " Bad input" << std::endl;
		return (1);
	}
	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open() == false)
	{
		std::cout << "Error: open failed" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	exchange("data.csv");
		std::string	str;
		while (std::getline(inputFile, str))
		{
			if((str[0] && isalpha(str[0])))
				std::getline(inputFile, str);
			std::stringstream ss(str);
			std::string date;
			double value;
			try
			{
			if (std::getline(ss, date, '|') && ss >> value )
			{
				date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
				date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
				double exchangeRate = exchange.getExchangeRate(date, value);
				double result = value * exchangeRate;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
			else
				std::cout << "Error: bad input => " << str << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout<< e.what()<<std::endl;
			}
		}
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);

}