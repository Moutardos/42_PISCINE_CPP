#include "Ice.hpp"

Ice::Ice (void) {

	this->_type = "ice";
}

Ice::Ice (Ice &other) {

	*this = other;
}

Ice::~Ice (void) {}

Ice	&Ice::operator= (Ice &other) {

	this->_type = other._type;

	return (*this);
}

Ice* Ice::clone() const {

	return (new Ice ());
}

void Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}