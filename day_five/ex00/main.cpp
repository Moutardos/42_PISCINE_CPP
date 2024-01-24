#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat fred("fred", 1);


	std::cout << fred << std::endl;
	std::cout << std::endl;

	try 
	{
		fred.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "There's an error !" << std::endl;
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << fred << std::endl;
	// fred.increment();

	std::cout << std::endl;

	{
		try 
		{
			Bureaucrat fakefred("non", 151);
			std::cout << fred << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "There's an error ! :" << std::endl;
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
