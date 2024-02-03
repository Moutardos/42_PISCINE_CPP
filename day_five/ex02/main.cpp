#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat fred("fred", 115);

	// Form	*formEmpty = new Form();
	// Form	*formStrict = new Form("strict", false, 2, 10);
	// Form	*formOkay = new Form("okay", false, 140, 134);

	// try 
	// {
	// 	formEmpty->beSigned(fred);
	// }
	// catch (std::exception e)
	// {
	// }
	// fred.signForm(*formEmpty);
	// try 
	// {
	// 	formStrict->beSigned(fred);
	// }
	// catch (std::exception e)
	// {
	// }
	// fred.signForm(*formStrict);
	// try 
	// {
	// 	formOkay->beSigned(fred);
	// }
	// catch (std::exception e)
	// {
	// }
	// fred.signForm(*formOkay);

	// std::cout << std::endl;
	// std::cout << std::endl;

	// std::cout << *formEmpty << std::endl;
	// std::cout << *formStrict << std::endl;
	// std::cout << *formOkay << std::endl;

	// delete formEmpty;
	// delete formStrict;
	// delete formOkay;
	return 0;
}
