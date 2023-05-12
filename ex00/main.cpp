/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:29 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 15:38:30 by mrafik           ###   ########.fr       */
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
		std::cerr << "Usage: " << argv[0] << " input.txt" << std::endl;
		return (1);
	}
	std::ifstream inputFile(argv[1]);
	if (inputFile.is_open() == false)
	{
		std::cerr << "Error: open failed" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	exchange("data.csv");
		std::string	str;
		std::getline(inputFile, str);
		while (std::getline(inputFile, str))
		{
			std::stringstream ss(str);
			std::string date;
			float value;
			try
			{
			if (std::getline(ss, date, '|') && ss >> value)
			{
				date.erase(0, date.find_first_not_of(" \t\n\r\f\v"));
				date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
				float exchangeRate = exchange.getExchangeRate(date, value);
				float result = value * exchangeRate;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
			else
				std::cerr << "Error: bad input => " << str << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr<< e.what()<<std::endl;
			}
		}
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);

}