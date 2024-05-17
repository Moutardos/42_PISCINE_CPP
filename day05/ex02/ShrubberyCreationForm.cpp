#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (void) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget("Unkonwn");
	this->_fname = this->getTarget() + "_shrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm	(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget(other.getTarget());
	this->_fname = this->getTarget() + "_shrubbery";
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator= (ShrubberyCreationForm &other)
{
	
	this->setTarget(other.getTarget());
	this->_fname = this->getTarget() + "_shrubbery";
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string target) : AForm("ShrubberyCreationForm", false, 137, 145){

	this->setTarget(target);
	this->_fname = this->getTarget() + "_shrubbery";
}

void ShrubberyCreationForm::executeAction (void) {

	try
	{
		this->_file.open(this->_fname.c_str());
		this->_file << "ASCII trees" << std::endl;
		if (this->_file.fail())
			std::cerr << "Error with " << this->_fname << " file" << std::endl;
		this->_file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
