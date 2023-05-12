/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:35 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 17:40:43 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include"RPN.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std:: cout << "Error: Use RPN <expression>!\n";
        return 0;
    }
    std:: string expression = argv[1];
	RPN tmp;
	try{
    	double result = tmp.calculate(expression);	
    	std:: cout << result << std:: endl;
	}
	catch(std::exception &e)
	{
		std::cout<< e.what() <<std::endl;
	}
    return 0;
}
