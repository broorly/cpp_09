/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:41 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 17:19:54 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include<string>
#include<iostream>
#include <stack>

class RPN
{ 
private:
  std::stack<double> _numbers;
public:
    RPN(/* args */);
	~RPN();
	RPN & operator=(const RPN & src );
    RPN(const RPN &rpn );
    double calculate(std::string expression);
    bool is_operator(std::string token);
    double evaluate(double a, double b, std::string op);
    class Error : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error");
				}
		};
};

