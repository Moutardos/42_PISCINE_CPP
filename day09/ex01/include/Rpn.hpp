#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

enum	e_operation
{
	OP_ADD, OP_SUB, OP_DIV, OP_MUL
};

class RPN
{
	private:
		std::string _rawExpr;
		std::stack<int> _data;

		void	treatOperator(char c);

	public:
		RPN	(void);
		RPN	(RPN &ref);
		RPN	(std::string expr);
		~RPN();

		RPN			&operator=(RPN &ref);
		std::string	getRaw(void);
		
};


#endif