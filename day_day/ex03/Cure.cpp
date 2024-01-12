#include "Cure.hpp"

Cure::Cure (void) {

	this->_type = "cure";
}

Cure::Cure (Cure &other) {

	*this = other;
}

Cure::~Cure (void) {}

Cure	&Cure::operator= (Cure &other) {

	this->_type = other._type;

	return (*this);
}

Cure* Cure::clone() const {

	return (new Cure ());
}

void Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}