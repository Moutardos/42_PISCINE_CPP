#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <iostream>
# include <iomanip>
# include <limits>
# include <sstream>
# include <stdlib.h>

struct valueData{
	char	value_char;
	bool	valid_char;
	int		value_int;
	bool	valid_int;
	float	value_float;
	bool	valid_float;
	double	value_double;
	bool	valid_double;
};

namespace Converter {

	bool	isChar		(std::string str);
	bool	isInt		(std::string str);
	bool	isFloat		(std::string str);
	bool	isDouble	(std::string str);

	void	convertChar		(std::string str, valueData &values);
	void	convertInt		(std::string str, valueData &values);
	void	convertFloat	(std::string str, valueData &values);
	void	convertDouble	(std::string str, valueData &values);

	void	initValueData	(valueData &values);
	void	displayValues	(valueData &values);
}

class ScalarConverter {

public:
    static void	convert	(std::string value);

private:
					ScalarConverter		(void);
					ScalarConverter		(ScalarConverter &ScalarConverter);
					~ScalarConverter	(void);
	ScalarConverter	&operator=			(ScalarConverter &c);

};



#endif
