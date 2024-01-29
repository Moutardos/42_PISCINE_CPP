#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (void) : AForm("PresidentialPardonForm", false, 5, 25),
_target("Unnamed") {}

PresidentialPardonForm::PresidentialPardonForm	(PresidentialPardonForm &other) : AForm("PresidentialPardonForm", false, 5, 25),
_target(other.getTarget()) {}

PresidentialPardonForm	&operator= (PresidentialPardonForm &other)

PresidentialPardonForm	(std::string target);

std::string getTarget (void) const {

	return (this->_target);
}