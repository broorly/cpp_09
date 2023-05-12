/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafik <mrafik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:38:38 by mrafik            #+#    #+#             */
/*   Updated: 2023/05/12 22:29:42 by mrafik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <sstream>
#include"RPN.hpp"

RPN::RPN()
{
	
}
RPN :: ~RPN()
{
	
}

RPN& RPN :: operator=(const RPN & src ){
	_numbers = src._numbers;
	return(*this);
}
RPN::RPN(const RPN& rpn)
{
	*this = rpn;
	return ;
}

bool RPN :: is_operator(std::string token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

double RPN :: evaluate(double a, double b, std::string op) {
    if (op == "+") {
        return a + b;
    } else if (op == "-") {
        return a - b;
    } else if (op == "*") {
        return a * b;
    } else if (op == "/") {
        if(b == 0)
            throw Error();
        return a / b;
    }
	return(0);
}

double RPN :: calculate(std::string expression)
{
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {
        if (!is_operator(token)) {
            double number;
            try {
                if(token.size() >= 2)
                {
                    for(size_t i=0; i < token.size();i++)
                    {
                        if(isnumber(token[i]))
                        {
                            number = token[i] - '0';
                            _numbers.push(number);
                        }
                    }
                }
                else
                {
                    number = std::stod(token);
                    _numbers.push(number);
                }
            } catch (...) 
			{
               throw Error();
            }
        }
		else {
            if (_numbers.size() < 2) {
                throw Error();
            }
            double b = _numbers.top();
            _numbers.pop();
            double a = _numbers.top();
            _numbers.pop();
            double result = evaluate(a, b, token);
            _numbers.push(result);
        }
    }
    if (_numbers.size() != 1)
		throw Error();
    return _numbers.top();
}
