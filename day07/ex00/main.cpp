#include <iostream>

#include "whatever.hpp"

template<typename T>
void	swap(T &value1, T &value2) {

	T	temp;

	temp = value1;
	value1 = value2;
	value2 = temp;
}

template<typename T>
T	min(T value1, T value2) {

	return (value1 < value2? value1: value2);
}

template<typename T>
T	max(T value1, T value2) {

	return (value1 > value2? value1: value2);
}

int main(void)
{
	std::string str1 = "I'm.. str1.. i think";
	std::string str2 = "I'm str2 for sure ! No doubt about it";

	std::cout << ::min<char>('Z', 'U') << ' ' << ::max<int>(-29999, -1230) << std::endl;

	::swap<std::string>(str1,str2);
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;

	return (0);
}
