#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

class RPN
{
	private:
		std::string 	_rawExpr;
		std::stack<int> _data;

		int		popNumber(void);
		int		popOperation(int left);
		void	pushOperation(int left);
		void	treatOperator(char c);

	public:
		RPN	(void);
		RPN	(RPN &ref);
		RPN	(std::string expr);
		~RPN();

		RPN				&operator=(RPN &ref);
		std::string		getRaw(void);
		int				getResult();
		std::stack<int>	getData();
		
};


#endif