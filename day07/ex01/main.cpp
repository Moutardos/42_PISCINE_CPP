#include <cstring>
#include <iostream>

#include "iter.hpp"

template<typename T>
void	iter(T *arr, unsigned int length, void (*f)(T &)) {

	for (unsigned int i = 0; i < length; i++)
		f(arr[i]);
}

void	plusAndPrint(const char &c)
{
	if (isalpha(c))
		std::cout << static_cast<char>(c + 1);
	else
		std::cout << (c);
}

void	addInt(int &n)
{
	n++;
}

void	printInt(int &n)
{
	std::cout << n << " ";
}

int main(int argc, char const *argv[])
{
	int	tab[5] = {1,2,3,0,-2};
	
	::iter<int>(tab, 5, &printInt);
	std::cout << std::endl;

	::iter<int>(tab, 5, &addInt);
	::iter<int>(tab, 5, &printInt);
	std::cout << std::endl;

	if (argc > 1)
	{
		::iter<const char>(argv[1], std::strlen(argv[1]), &plusAndPrint);
		std::cout << std::endl;
	}
	return 0;
}


