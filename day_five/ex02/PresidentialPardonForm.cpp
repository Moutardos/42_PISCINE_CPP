#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (void) : AForm("PresidentialPardonForm", false, 5, 25){

	this->setTarget("Unkown");
}

PresidentialPardonForm::PresidentialPardonForm	(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", false, 5, 25){

	this->setTarget(other.getTarget());
}

PresidentialPardonForm	&PresidentialPardonForm::operator= (PresidentialPardonForm &other)
{
	
	this->setTarget(other.getTarget());
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm (std::string target) : AForm("PresidentialPardonForm", false, 5, 25) {

	this->setTarget(target);
}

void	PresidentialPardonForm::executeAction	(void) {

	std::cout << "it's me, president" << std::endl;
}