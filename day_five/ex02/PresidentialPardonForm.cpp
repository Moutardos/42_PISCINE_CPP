#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (void) : AForm("PresidentialPardonForm", false, 5, 25),
_target("Unnamed") {}

PresidentialPardonForm::PresidentialPardonForm	(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", false, 5, 25),
_target(other.getTarget()) {}

PresidentialPardonForm	&PresidentialPardonForm::operator= (PresidentialPardonForm &other)
{
	
	this->_target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm	(std::string target) : AForm("PresidentialPardonForm", false, 5, 25),
_target(target) {}