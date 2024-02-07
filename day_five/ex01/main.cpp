#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat fred("fred", 115);

	Form	*formEmpty = new Form();
	Form	*formStrict = new Form("strict", false, 2, 10);
	Form	*formOkay = new Form("okay", false, 140, 134);

	std::cout << fred << std::endl;

	fred.signForm(*formEmpty);
	fred.signForm(*formStrict);
	fred.signForm(*formOkay);

	std::cout << std::endl;

	std::cout << *formEmpty;
	std::cout << *formStrict;
	std::cout << *formOkay;

	delete formEmpty;
	delete formStrict;
	delete formOkay;
	return 0;
}
