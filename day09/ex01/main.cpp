#include "Rpn.hpp"
#include "logger.hpp"

int main(int argc, char const *argv[])
{
	std::string	expr;

	if (argc > 1)
		expr = argv[1];
	try
	{
		RPN rpn(expr);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		LOG_ERROR(e.what());
	}
	return (0);
}