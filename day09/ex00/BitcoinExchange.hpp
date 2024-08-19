#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>

class Date
{
	private:
		Date();

		unsigned int	day;
		unsigned int	month;
		unsigned int	year;
	
	public:
		Date(std::string date);
		Date(Date const &ref);
		Date &operator=(Date const &ref);
		~Date();

		bool	operator==(Date const &ref);

		unsigned int	getDay(void) const;
		unsigned int	getMonth(void) const;
		unsigned int	getYear(void) const;
};

std::ostream	&operator<< (std::ostream &os, const Date &date);

class	BitcoinExchange
{
	private:
		std::map<Date, float>	_data;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ref);
		BitcoinExchange &operator=(BitcoinExchange const &ref);
		~BitcoinExchange();
};

#endif
