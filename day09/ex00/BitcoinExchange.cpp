#include "BitcoinExchange.hpp"
#include "logger.hpp"
#include "algorithm"
/* Date */
Date::Date(void) {

	this->year = 0;
	this->month = 0;
	this->day = 0;
}
Date::Date(Date const &ref) 
{
	*this = ref;
}
Date &Date::operator=(Date const &ref)
{
	this->year = ref.getYear();
	this->month = ref.getMonth();
	this->day = ref.getDay();
	return (*this);
}

Date::~Date() {}

Date::Date(std::string date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw std::invalid_argument(date + ": Format of date should be yyyy-mm-dd");
	std::size_t pos = 0;
	std::size_t	posEnd = date.find('-');
	std::string	buffer;

	for (int i = 0; i < 3; i++)
	{
		buffer = date.substr(pos, posEnd - pos);
		pos = posEnd + 1;
		posEnd = date.find_last_of('-');
		if (pos == std::string::npos && i < 2)
			throw std::invalid_argument(date + ": Format of date should be yyyy-mm-dd");
		if (buffer.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument(date + ": Format of date should be yyyy-mm-dd");
		switch(i)
		{
			case 0:
				setYear(buffer);
				break;
			case 1:
				setMonth(buffer);
				break;
			case 2:
				setDay(buffer);
				break;
		}
	}
}

bool	Date::operator==(Date const &ref)
{
	return (this->year == ref.getYear()
			&& this->month == ref.getMonth()
			&& this->day == ref.getDay());
}

bool	Date::operator<(Date const &ref) const
{
	if (this->year == ref.getYear())
	{
		if (this->month == ref.getMonth())
		{
			return (this->day < ref.getDay());
		}
		return (this->month < ref.getMonth());
	}
	return (this->year < ref.getYear());
}

bool	Date::operator>(Date const &ref) const
{
	if (this->year == ref.getYear())
	{
		if (this->month == ref.getMonth())
		{
			return (this->day > ref.getDay());
		}
		return (this->month > ref.getMonth());
	}
	return (this->year > ref.getYear());
}


std::ostream	&operator<< (std::ostream &os, const Date &date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return (os);
}

unsigned int	Date::getDay(void) const
{
	return (this->day);
}

unsigned int	Date::getMonth(void) const
{
	return (this->month);
}

unsigned int	Date::getYear(void) const
{
	return (this->year);	
}

void	Date::setDay(std::string buffer)
{
	unsigned long tmp = strtoul(buffer.c_str(), NULL, 10);
	if (tmp >= std::numeric_limits<unsigned int>::max() || tmp > 31)
		throw std::invalid_argument("day cannot be " + buffer );
	this->day = tmp;
}

void	Date::setMonth(std::string buffer)
{
	unsigned long tmp = strtoul(buffer.c_str(), NULL, 10);
	if (tmp >= std::numeric_limits<unsigned int>::max() || tmp > 12)
		throw std::invalid_argument("month cannot be " + buffer );
	this->month = tmp;
}
void	Date::setYear(std::string buffer)
{
	unsigned long tmp = strtoul(buffer.c_str(), NULL, 10);
	if (tmp >= std::numeric_limits<unsigned int>::max())
		throw std::invalid_argument("year cannot be " + buffer );
	this->year = tmp;
}

/* BitcoinExchange*/
BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &ref)
{
	*this = ref;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &ref)
{
	this->_filename = ref.getFileName();
	this->_fileData.open(DATABASE_FILENAME, std::ios_base::in);
	if (!this->_fileData.good())
		throw std::invalid_argument("Couldn't open the database");
	this->_fileStock.open(_filename.c_str(), std::ios_base::in);
	if (!this->_fileStock.good())
	{
		this->_fileData.close();
		throw std::invalid_argument("Couldn't open " + _filename);
	}
	this->_data = ref.getData();
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::string	line;

	this->_filename = filename;
	this->_fileStock.open(filename.c_str(), std::ios_base::in);
	this->_fileData.open(DATABASE_FILENAME, std::ios_base::in);
	if (!this->_fileData.good())
		throw std::invalid_argument("Couldn't open the database");
	if (!this->_fileStock.good())
	{
		this->_fileData.close();
		throw std::invalid_argument("Couldn't open file " + this->_filename );
	}
	std::getline(this->_fileData, line); // Ignore first line
	while (std::getline(this->_fileData, line) && !line.empty())
		treatLine(line, BTC_DATABASE);
	std::getline(this->_fileStock, line); // Ignore first line
	while (std::getline(this->_fileStock, line) && !line.empty())
	{
		try 
		{
			treatLine(line, BTC_STOCK);
		}
		catch (std::invalid_argument e)
		{
			LOG_ERROR(e.what());
		}
	}
}


BitcoinExchange::~BitcoinExchange()
{
	this->_fileStock.close();
}

const std::string	&BitcoinExchange::getFileName(void) const
{
	return (_filename);
}

const std::map<Date, float>	&BitcoinExchange::getData(void) const
{
	return (_data);
}

float	BitcoinExchange::treatLine(std::string line, t_btcfile btcfile)
{
	std::string			dateStr;
	std::string			valueStr;
	std::string			sep;
	std::size_t			posEnd;
	Date				date;
	if (btcfile == BTC_DATABASE)
		sep = ",";
	else
		sep = " | ";

	posEnd = line.rfind(sep);

	if (posEnd == std::string::npos)
		throw std::invalid_argument(line + ": Couldn't find separator \"" + sep + "\"");
	LOG_INFO(line);
	dateStr = line.substr(0, posEnd);
	valueStr = line.substr(posEnd + sep.length());
	if (dateStr.empty() || valueStr.empty())
		throw std::invalid_argument(line + ": Bad input => " + dateStr + " " + valueStr);
	try
	{
		date = Date(dateStr);
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument(line + ": Incorrect date \"" + e.what() + "\"");
	}
	if (btcfile == BTC_STOCK)
	{
		if (valueStr.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument(line + ": " + valueStr + " is not a correct value [Integer between 0-1000]");		
	}
	else
		if (valueStr.find_first_not_of("0123456789.") != std::string::npos || std::count(valueStr.begin(), valueStr.end(), '.') > 1)
			throw std::invalid_argument(line + ": " + valueStr + " is not a correct value [Positive decimal]");		

	double	value = strtod (valueStr.c_str(), NULL);
	if (value < 0)
		throw std::invalid_argument(line + ": " + valueStr + " not a positive number");		
	if (btcfile == BTC_STOCK)
	{
		if (value > 1000)
			throw std::invalid_argument(line + ": " + valueStr + " too large a number");		
	}
	try
	{
		if (btcfile == BTC_DATABASE)
			this->_data[date] =  value;
		else
			return (_data.upper_bound(date)->second * value);
	}
	catch(const std::invalid_argument& e)
	{
		throw std::invalid_argument(line + ": " + dateStr + ": " + e.what());		
	}
	return (0);
}

void	BitcoinExchange::displayStock(void)
{
	std::string		line;
	std::string		dateStr;
	std::string		amountStr;
	std::getline(this->_fileStock, line); // Ignore first line


	while (std::getline(this->_fileStock,dateStr, ',') && !dateStr.empty()
			&& std::getline(this->_fileStock, amountStr))
	{

		try 
		{
			if (amountStr.empty())
				throw std::invalid_argument("Bad input => " + dateStr + " " + amountStr);
			if (amountStr.find_first_not_of("0123456789") != std::string::npos)
				throw std::invalid_argument(line + ": " + amountStr + " is not a correct value");		
			float	amount = std::atoi(amountStr.c_str());
			if (amount < 0)
				throw std::invalid_argument("Not a positive number");
			Date	date(dateStr);
			std::map<Date, float>::iterator	nearestDateIt = _data.upper_bound(date);
			if (nearestDateIt == _data.end())
				std::advance(nearestDateIt, -1);
			double sum = nearestDateIt->second * amount;
			std::cout << std::fixed << dateStr << " => " << amount << " = " << sum;
		}
		catch (std::invalid_argument e)
		{
			LOG_ERROR(e.what());
		}
		std::cout << std::endl;
	}
	// LOG_INFO("bonsoir je suis la");
	// for (std::map<Date, float>::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	// {
	// 	LOG_INFO(it->first);
	// 	LOG_INFO("bonsoir");
	// }
}

