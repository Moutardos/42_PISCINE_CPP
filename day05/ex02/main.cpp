#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	Bureaucrat	fred("fred", 115);
	Bureaucrat	ted("ted", 2);
	Bureaucrat	stagiaire("stagiaire",150);

	AForm	*presForm = new PresidentialPardonForm(ted.getName());
	AForm	*robotForm = new RobotomyRequestForm(fred.getName());
	AForm	*shrubForm = new ShrubberyCreationForm(stagiaire.getName());

	srand(time(NULL));
	ted.signForm(*presForm);
	ted.signForm(*robotForm);
	ted.signForm(*shrubForm);

	std::cout << std::endl;
	stagiaire.executeForm(*presForm);
	std::cout << std::endl;
	ted.executeForm(*presForm);
	std::cout << std::endl;
	ted.executeForm(*robotForm);
	ted.executeForm(*robotForm);
	ted.executeForm(*robotForm);
	std::cout << std::endl;
	ted.executeForm(*shrubForm);

	delete presForm;
	delete robotForm;
	delete shrubForm;
	return 0;
}
