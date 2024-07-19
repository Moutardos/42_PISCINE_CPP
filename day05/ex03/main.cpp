#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {

	Bureaucrat	fred("fred", 115);
	Bureaucrat	ted("ted", 2);
	Bureaucrat	stagiaire("stagiaire",150);
	Intern		who;

	AForm	*presForm;
	AForm	*robotForm;
	AForm	*shrubForm;

	bool	exception = false;


	try
	{
		presForm = who.makeForm("presidential pardon", ted.getName());
		robotForm = who.makeForm("robotomy request", fred.getName());
		shrubForm = who.makeForm("shrubbery creation", stagiaire.getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exception = true;
	}
	try
	{
		robotForm = who.makeForm("roburwlvg[tomy request", fred.getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ": " << "roburwlvg[tomy request" << '\n';
		exception = true;
	}

	if (exception)
	{
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
	}
	return (0);
}