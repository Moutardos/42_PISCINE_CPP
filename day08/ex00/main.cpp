#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
# include <algorithm>

//throw error  if it == end();
template<typename T>
typename T::iterator	easyfind(T&container, int x) {

	typename T::iterator it = std::find(container.begin(), container.end(), x);
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
		e = easyfind< std::vector<int> >(vector, -1);
		std::cout << *e << std::endl;

		std::cout << "\n";
	}
	// {
	// 	std::list<int>				list;
	// 	std::list<int>::iterator	it;

	// 	for (i = 0; i < 10; ++i)
	// 		list.push_back(i);
	// 	easyfind< std::list<int> >(list, 9) = 42;
	// 	for (it = list.begin(); it != list.end(); ++it)
	// 		std::cout << *it << " ";
	// 	std::cout << "\n";

	// 	try
	// 	{
	// 		easyfind< std::list<int> >(list, 20);
	// 	}
	// 	catch (std::exception &e)
	// 	{
	// 		std::cout << "Error: " << e.what() << "\n";
	// 	}
	// }
}