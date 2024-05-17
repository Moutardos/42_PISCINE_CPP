#include "Dog.hpp"

Dog::Dog (void) {

	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
};

Dog::Dog (Dog &Dog) {

	std::cout << "Dog copy constructor called" << std::endl;

	*this = Dog;
}

Dog::~Dog (void) {

	std::cout << "Dog default destructor called" << std::endl;
}


Dog &Dog::operator=(Dog &c) {

	std::cout << "Dog copy operator called" << std::endl;

	this->_type = c._type;
	
	return (*this);
}

void Dog::makeSound (void) const {

	std::cout << this->_type << ": AWOOOOOF" << std::endl;
}
