#include "Rpn.hpp"

RPN::RPN(void)
{
	_rawExpr = "";
}

RPN::RPN(RPN &ref)
{
	*this = ref;
}

RPN::RPN(std::string expr)
{
	this->_rawExpr = expr;
	for (std::string::iterator it = expr.begin(); it != expr.end(); it++)
	{
		char c = *it;
		if (std::isspace(c))
			continue;
		else if (std::isdigit(c))
			_data.push(c - '0');
		else
			treatOperator(c);
	}
	if (_data.size() > 1 || _data.size() == 0)
		throw std::out_of_range("RPN: bad number of operations/digit");
}
RPN &RPN::RPN::operator=(RPN &ref)
{
	this->_rawExpr = ref.getRaw();
	this->_data = ref.getData();
	return (*this);
}

void	RPN::treatOperator(char c)
{
	if (_data.size() < 2)
	{
		throw std::out_of_range("treatOperator: not enough number for operation");
	}
	int num = popNumber();
	switch(c)
	{
		case '+':
			this->_data.top() += num;
			break;
		case '-':
			this->_data.top() -= num;
			break;
		case '*':
			this->_data.top() *= num;
			break;
		case '/':
			if (num == 0)
				throw std::invalid_argument("treatOperator: division by 0");
			this->_data.top() /= num;
			break;		
		default :
			throw std::invalid_argument("TreatOperator: not a valid operator");
	};
}
// int	RPN::popOperation(int left)
// {
// 	int			right;
// 	e_operation	op;

// 	if (_data.size() < 2)
// 	{
// 		throw std::out_of_range("doOperation: out_of_range");
// 	}
// 	right = popDigit();
// 	if (_data.front() > 0)
// 	{
// 		left = popOperation(right);
// 	}
// 	op = static_cast<e_operation>(_data.front());
// 	if (op >= 0)
// 		throw std::invalid_argument("doOperation: expected an operator");
// 	_data.pop();
// }

int	RPN::popNumber(void)
{
	int	number;

	if (_data.size() < 1)
	{
		throw std::out_of_range("popNumber: out_of_range");
	}
	number = _data.top();
	_data.pop();
	return (number);
}

std::string	RPN::getRaw(void)
{
	return (this->_rawExpr);
}

int	RPN::getResult(void)
{
	return (this->_data.top());
}

std::stack<int>	RPN::getData()
{
	return (_data);
}
RPN::~RPN()
{

}
