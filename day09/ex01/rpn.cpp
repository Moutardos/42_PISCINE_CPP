#include "Rpn.hpp"

RPN::RPN(void)
{
	
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
			_data.push(c);
		else
			treatOperator(c);
		
	}
}
RPN &RPN::RPN::operator=(RPN &ref)
{
	this->_rawExpr = ref.getRaw();
	return (*this);
}

void	RPN::treatOperator(char c)
{
	switch(c)
	{
		case '+':
			this->_data.push(e_operation::OP_ADD);
			break;
		case '-':
			this->_data.push(e_operation::OP_SUB);
			break;
		case '*':
			this->_data.push(e_operation::OP_MUL);
			break;
		case '/':
			this->_data.push(e_operation::OP_DIV);
			break;		
		default :
			throw std::invalid_argument(c + " is not a valid operator");
	};
}
RPN::~RPN()
{

}
