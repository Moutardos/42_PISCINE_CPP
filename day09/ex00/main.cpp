#include "BitcoinExchange.hpp"
#include "logger.hpp"

int main(int argc, char const *argv[])
{
	std::string	filename;
	BitcoinExchange btcStock;

	if (argc != 2)
		filename = "";
	else
		filename = argv[1];
	try 
	{
		btcStock = BitcoinExchange(filename);
		btcStock.displayStock();
	}
	catch (std::invalid_argument e)
	{
		LOG_ERROR(e.what());
		return (0);
	}
	return (0);
}