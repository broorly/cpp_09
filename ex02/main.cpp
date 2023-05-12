/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:19 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 15:38:20 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
    try
    {
       PmergeMe input(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}
