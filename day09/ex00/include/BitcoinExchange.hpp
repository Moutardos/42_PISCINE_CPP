#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define DATABASE_FILENAME "data.csv"

// BTC OPTION
# define BTC_DATABASE true
# define BTC_STOCK false

# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <stdexcept>
# include <limits>
# include <climits>

typedef bool t_btcfile;


class Date
{
	private:
		unsigned int	day;
		unsigned int	month;
		unsigned int	year;
	
	public:
		Date();
		Date(std::string date);
		Date(Date const &ref);
		Date &operator=(Date const &ref);
		~Date();

		bool	operator==(Date const &ref);
		bool	operator<(Date const &ref) const;
		bool	operator>(Date const &ref) const;

		unsigned int	getDay(void)	const;
		unsigned int	getMonth(void)	const;
		unsigned int	getYear(void)	const;
		void			setDay(std::string);
		void			setMonth(std::string);
		void			setYear(std::string);

};

std::ostream	&operator<< (std::ostream &os, const Date &date);

class	BitcoinExchange
{
	private:
		std::map<Date, float>	_data;
		std::ifstream			_fileData;
		std::ifstream			_fileStock;
		std::string				_filename;
		
		void	fillData(void);
		float	treatLine(std::string line, t_btcfile btcfile);

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &ref);
		BitcoinExchange &operator=(BitcoinExchange const &ref);
		~BitcoinExchange();
		
		BitcoinExchange(std::string filename);

		const std::string				&getFileName(void)	const;
		const std::map<Date, float>		&getData(void)	const;
		void					displayStock(void);
};

#endif
