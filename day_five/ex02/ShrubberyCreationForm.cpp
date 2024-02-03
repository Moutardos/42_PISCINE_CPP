#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (void) : AForm("ShrubberyCreationForm", false, 5, 25),
_target("Unnamed") {}

ShrubberyCreationForm::ShrubberyCreationForm	(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", false, 5, 25),
_target(other.getTarget()) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (ShrubberyCreationForm &other)
{
	
	this->_target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm	(std::string target) : AForm("ShrubberyCreationForm", false, 5, 25),
_target(target) {}