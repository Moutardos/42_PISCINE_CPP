#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(ScalarConverter &sc) {

	sc = *this;
}
ScalarConverter::~ScalarConverter(void) {}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter &c) {

	(void) c;
	return (*this);    
}

void ScalarConverter::convert(std::string value) {

	valueData	values;

	Converter::initValueData(values);
	if (Converter::isChar(value)) 
		Converter::convertChar(value, values);
	else if (Converter::isInt(value))
		Converter::convertInt(value, values);
	else if (Converter::isDouble(value))
		Converter::convertDouble(value, values);
	else if (Converter::isFloat(value))
		Converter::convertFloat(value, values);
	else
	{
		std::cerr << "String is not valid" << std::endl;
		return ;
	}
	Converter::displayValues(values);
}
