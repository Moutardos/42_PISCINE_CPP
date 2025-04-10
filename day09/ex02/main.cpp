#include "PmergeMe.hpp"
#include <list>
#include <deque>
#include <ctime>
#include <limits>

std::list<int>	convertList(char **av)
{
	std::list<int>	results;
	long			raw;

	av++;
	for (; *av != NULL; av++)
	{
		std::string rawString;
		rawString = std::string(*av);
		if (((!isdigit(rawString.at(0)) && rawString.at(0) != '-') || (rawString.at(0) == '-' &&  rawString.size() < 2))
				|| rawString.find_first_not_of("0123456789",1) != std::string::npos)
			throw std::invalid_argument(rawString +  " is not a valid number");
		raw = atoi(*av);
		if (raw >= std::numeric_limits<int>::max() || raw <= std::numeric_limits<int>::min())
			throw std::invalid_argument(rawString + " is out of int limit");
		results.push_back(atoi(*av));
	}
	return (results);
}

int main(int ac, char **av)
{
	std::list<int>	userInput;

	if (ac == 1)
		return (0);

	try
	{
		userInput = convertList(av);
	}
	catch(const std::exception& e)
	{
		LOG_ERROR(e.what() << ": Couldn't convert string to int" << std::endl);
		return (1);
	}

	if (!DEBUG)
		mergeInsertSort<std::list, int>(userInput, true);

	std::time_t start = std::clock();
	mergeInsertSort<std::list, int>(userInput);
	std::time_t	timeList = std::clock() - start;

	std::cout << std::endl << "Number of comparaison for list is " << compCount << " !" << std::endl;
	std::cout << "Time to proceed " << userInput.size() << " elements with list is : " << 1000.0 * (timeList) / CLOCKS_PER_SEC << " ms" << std::endl;
	std::cout << std::endl;

	start = std::clock();
	mergeInsertSort<std::deque, int>(userInput);
	std::time_t	timeDeque = std::clock() - start;
	std::cout << std::endl << "Number of comparaison for deque is " << compCount << " !" << std::endl;
	std::cout << "Time to proceed " << userInput.size() << " elements with deque is : " << 1000.0 * (timeDeque) / CLOCKS_PER_SEC << " ms" << std::endl;

	return (0);
}
