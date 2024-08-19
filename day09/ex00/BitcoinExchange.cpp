#include "BitcoinExchange.hpp"

/* Date */
Date::Date(void) {}
Date::Date(Date const &ref) 
{
	*this = ref;
}
Date &Date::operator=(Date const &ref)
{
	this->year = ref.getYear();
	this->month = ref.getMonth();
	this->day = ref.getDay();

}

Date::~Date() {}

Date::Date(std::string date)
{
	std::size_t pos = 0;
	std::size_t	posEnd = date.find('-');

	for (int i = 0; i < 3; i++)
	{
		date.substr(pos, posEnd);
		pos = posEnd;
		posEnd = date.find("-");
		if (pos == std::string::npos && i < 2)
			throw std::invalid_argument("Format of date should be yyyy-mm-dd");
	}
	//check pour deux - et correct y-m-d

}

bool	Date::operator==(Date const &ref)
{
	return (this->year == ref.getYear()
			&& this->month == ref.getMonth()
			&& this->day == ref.getDay());
}

std::ostream	&operator<< (std::ostream &os, const Date &date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return (os);
}

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref)
{
	*this = ref;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &ref)
{
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}
