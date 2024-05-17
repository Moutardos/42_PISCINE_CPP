#include "Animal.hpp"

Animal::Animal (void): _type("Basic Animal") {

	std::cout << "Animal default constructor called" << std::endl;
};

Animal::Animal (Animal &animal) {

	std::cout << "Animal copy constructor called" << std::endl;

	*this = animal;
}

Animal::~Animal (void) {

	std::cout << "Animal default destructor called" << std::endl;
}

Animal &Animal::operator=(Animal &c) {

	this->_type = c._type;
	std::cout << this->_type << " copy operator called" << std::endl;
	
	return (*this);
}

std::string Animal::getType	(void) const {

	return (this->_type);
}

void Animal::makeSound (void) const {
}
