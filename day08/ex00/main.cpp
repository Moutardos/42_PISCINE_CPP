#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>

template<typename T>
typename T::iterator	easyfind(T&container, int x)  {

	std::stringstream	error;

	typename T::iterator it = std::find(container.begin(), container.end(), x);
	if (it == container.end())
	{
		error << "couldn't find " << x << " in container";
		throw std::domain_error(error.str());
	}
	return (it);
}

int	main(void)
{
	int	i;

	{
		std::vector<int>	vector;
		std::vector<int>::iterator e;
		for (i = 0; i < 10; ++i)
			vector.push_back(i);
		e = easyfind< std::vector<int> >(vector, 4);
		std::cout << *e << std::endl;
		try {
			e = easyfind< std::vector<int> >(vector, -1);
			std::cout << *e << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}