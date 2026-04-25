#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& src) : _stack(src._stack)
{
}

RPN&	RPN::operator=(const RPN& src)
{
	if (this != &src)
		this->_stack = src._stack;
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(char c) const
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::applyOperator(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
    int v2 = _stack.top();
    _stack.pop();
    int v1 = _stack.top();
    _stack.pop();

    int result = 0;
    if (op == '+')
		result = v1 + v2;
    else if (op == '-')
		result = v1 - v2;
    else if (op == '*')
		result = v1 * v2;
    else if (op == '/')
	{
        if (v2 == 0)
			throw std::runtime_error("Error");
        result = v1 / v2;
    }
    _stack.push(result);
}

void RPN::calculate(const std::string& str)
{
    std::istringstream iss(str);
    std::string token;

    try
	{
        while (iss >> token)
		{
            if (token.length() == 1)
			{
                char c = token[0];
                if (std::isdigit(c))
				{
                    _stack.push(c - '0');
                }
				else if (isOperator(c))
				{
                    applyOperator(c);
                }
				else
				{
                    throw std::runtime_error("Error");
                }
            }
			else
			{
                throw std::runtime_error("Error");
            }
        }
        if (_stack.size() != 1)
		{
            throw std::runtime_error("Error");
        }
        std::cout << _stack.top() << std::endl;
        _stack.pop();

    } catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
        while (!_stack.empty())
			_stack.pop();
    }
}
