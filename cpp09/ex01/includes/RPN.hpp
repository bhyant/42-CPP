#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

class RPN
{
	public:
		RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		void calculate(const std::string& str);

	private:
		std::stack<int> _stack;
		bool	isOperator(char c) const;
		void	applyOperator(char op);
};
