#include "Intern.hpp"

Intern::Intern	(void) {}

Intern::Intern	(Intern &other) {
    (void) other;
}

Intern	&Intern::operator= (Intern &other){

    (void) other;
    return (*this);
}

Intern::~Intern	(void) {}

AForm	*Intern::makeForm(std::string formName, std::string target) {

    static 	const	std::string	formsName[FORM_MAX] = FORMS_NAMES;
    int                         n = -1;

    for (int i = 0; i < FORM_MAX; i++)
    {
        if (formsName[i] == formName)
            n = i;
    }

	switch (n)
    {
        case 0:
            return (new PresidentialPardonForm(target));
        case 1:
            return (new RobotomyRequestForm(target));
        case 2:
            return (new ShrubberyCreationForm(target));
        default:
            throw   Intern::FormError();

    }
}