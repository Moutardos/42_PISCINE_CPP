#include "AMateria.hpp"

AMateria::AMateria (void) : _type("void") {}


AMateria::AMateria (std::string const & type) : _type(type) {}

AMateria::AMateria	(AMateria &other) {

	*this = other;
}
AMateria::~AMateria	(void) {}

AMateria	&AMateria::operator= (AMateria &other) {

	this->_type = other._type;

	return (*this);
}

std::string const & AMateria::getType() const {

	return (this->_type);
}

AMateria* AMateria::clone() const {

	return (NULL);
}

void AMateria::use(ICharacter& target) {

	std::cout << "BZZZZZZZ tried to use the member function use of AMateria on" << target.getName()  << std::endl;
	std::cout << "* This shouldn't happen ! blame lcozdenm.." << std::endl;
}
