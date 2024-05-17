#include "ScalarConverter.hpp"

bool	Converter::isChar(std::string str) {

	return (str.length() == 1 && (!std::isdigit(str.at(0))));
}

void	Converter::convertChar(std::string str, valueData &values) {

	values.value_char = str.at(0);
	if (std::isprint(values.value_char))
		values.valid_char = true;
	values.value_int = static_cast<int>(values.value_char);
	values.value_float =  static_cast<float>(values.value_char);
	values.value_double = static_cast<double>(values.value_char);
}

bool	Converter::isInt(std::string str) {

	int64_t	raw;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (it == str.begin() && *it == '-')
			;
		else if (!std::isdigit(*it))
			return (false);
	}
	std::stringstream(str) >> raw;
	if (raw > std::numeric_limits<int>::max() || raw < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

void	Converter::convertInt(std::string str, valueData &values) {

	std::stringstream(str) >> values.value_int;
	if (values.value_int <= std::numeric_limits<char>::max() && values.value_int >= std::numeric_limits<char>::min() && 
			std::isprint(static_cast<char>(values.value_int)))
	{
		values.value_char = static_cast<char>(values.value_int);
	}
	else
		values.valid_char = false;
	values.value_float =  static_cast<float>(values.value_int);
	values.value_double = static_cast<double>(values.value_int);
}

bool	Converter::isFloat	(std::string str) {

	size_t	dp_c = 0;
	double	raw;

	if (str == "+inff" || str == "-inff" || str == "nanf")
		return (true);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (it == std::prev(str.end()) && *it == 'f')
		{
			;
		}
		else if (it == str.begin() && *it == '-')
			;
		else if (!std::isdigit(*it))
		{
			if (*it == '.')
				dp_c++;
			if (*it != '.' || dp_c > 1)
				return (false);
		}
	}
	std::stringstream(str) >> raw;
	if (raw > std::numeric_limits<float>::max() || raw < std::numeric_limits<float>::min())
		return (false);
	return (true);
}

void	Converter::convertFloat(std::string str, valueData &values) {

	values.value_float = strtof(str.c_str(), NULL);
	if (values.value_float <= std::numeric_limits<char>::max() && values.value_float >= std::numeric_limits<char>::min() && 
			std::isprint(static_cast<char>(values.value_float)))
		values.value_char = static_cast<char>(values.value_float);
	else
		values.valid_char = false;
	if (static_cast<int>(values.value_float) <= std::numeric_limits<int>::max() && static_cast<int>(values.value_float) < std::numeric_limits<int>::min())
		values.value_int = static_cast<int>(values.value_float);
	else
		values.valid_int = false;
	values.value_double = static_cast<double>(values.value_float);
}

bool	Converter::isDouble	(std::string str) {

	int		dp_c = 0;
	double	raw;
	
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (true);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (it == str.begin() && *it == '-')
			;
		else if (!std::isdigit(*it))
		{
			if (*it == '.')
				dp_c++;
			if (*it != '.' || dp_c > 1)
				return (false);
		}
	}
	std::stringstream(str) >> raw;
	if (raw > std::numeric_limits<double>::max() || raw < std::numeric_limits<double>::min())
		return (false);
	return (true);
}

void	Converter::convertDouble(std::string str, valueData &values) {

	values.value_double = strtod(str.c_str(), NULL);
	if (values.value_double <= std::numeric_limits<char>::max() && values.value_double >= std::numeric_limits<char>::min() && 
			std::isprint(static_cast<char>(values.value_double)))
		values.value_char = static_cast<char>(values.value_double);
	else
		values.valid_char = false;
	if (values.value_double <= std::numeric_limits<int>::max() && values.value_double >= std::numeric_limits<int>::min())
		values.value_int = static_cast<int>(values.value_double);
	else
		values.valid_int = false;
	if (values.value_double != values.value_double)
	{
		values.value_float = std::numeric_limits<float>::quiet_NaN();
	}
	if (values.value_double == std::numeric_limits<float>().infinity() || values.value_double == std::numeric_limits<float>().infinity() * -1)
		values.value_float = values.value_double;
	else if (values.value_double <= std::numeric_limits<float>::max() && values.value_double >= std::numeric_limits<float>::min())
		values.value_float = static_cast<float>(values.value_double);
	else
		values.valid_float = false;
}

void	Converter::initValueData(valueData &values) {

	values.valid_char = true;
	values.valid_int = true;
	values.valid_float = true;
	values.valid_double = true;	
}

void	Converter::displayValues(valueData &values) {

	static const std::string valuesType[4] = {
		"char: ",
		"int: ",
		"float :",
		"double :"
	};
	for (int i = 0; i < 4; i++)
	{
		std::cout << valuesType[i];
		switch (i)
		{
			case 0:
				if (values.valid_char)
					std::cout << values.value_char << std::endl;
				else
					std::cout << "impossible" << std::endl;
				break;
			case 1:
				if (values.valid_int)
					std::cout << values.value_int << std::endl;
				else
					std::cout << "impossible" << std::endl;
				break;
			case 2:
				if (values.valid_float)
				{
					std::cout << std::fixed << std::setprecision(1) << values.value_float << "f" << std::endl;
				}
				else
					std::cout << "impossible" << std::endl;
				break;
			case 3:
				if (values.valid_double)
					std::cout << std::fixed << std::setprecision(1) << values.value_double << std::endl;
				else
					std::cout << "impossible" << std::endl;
		}
	}
}