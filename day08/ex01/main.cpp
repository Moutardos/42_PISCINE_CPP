#include "Span.hpp"

int	main(void)
{
	Span	span(4);

	//fix empty
	// std::cout << span.shortestSpan() << std::endl;
	// std::cout << span.highestSpan() << std::endl;
	// std::cout << std::endl;
	
	span.addNumber(1);
	span.addNumber(10);
	
	std::cout << "shortest span:" << span.shortestSpan() << std::endl;
	std::cout << "highest span:" << span.highestSpan() << std::endl;
	std::cout << std::endl;
	span.addNumber(100000);

	std::cout << "shortest span:" << span.shortestSpan() << std::endl;
	std::cout << "highest span:" << span.highestSpan() << std::endl;
	std::cout << std::endl;

	span.addNumber(4);

	std::cout << "shortest span:" << span.shortestSpan() << std::endl;
	std::cout << "highest span:" << span.highestSpan() << std::endl;
	std::cout << std::endl;
}