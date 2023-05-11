#pragma once
#include<string>
#include<iostream>
#include <stack>

class RPN
{ 
private:
    /* data */
public:
    RPN(/* args */);
    ~RPN();
    RPN( std::string input );
		RPN( RPN & src );
		~RPN( void );

		RPN & operator=( RPN & src );
};

