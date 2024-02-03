#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (void) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget("Unkown");
}

ShrubberyCreationForm::ShrubberyCreationForm	(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget(other.getTarget());
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (ShrubberyCreationForm &other)
{
	
	this->setTarget(other.getTarget());
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget(target);
}