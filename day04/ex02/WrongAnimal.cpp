#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal (void): _type("Basic WrongAnimal") {

	std::cout << "WrongAnimal default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal (WrongAnimal &WrongAnimal) {

	std::cout << "WrongAnimal copy constructor called" << std::endl;

	*this = WrongAnimal;
}

WrongAnimal::~WrongAnimal (void) {

	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &c) {

	this->_type = c._type;
	std::cout << this->_type << " copy operator called" << std::endl;
	
	return (*this);
}

std::string WrongAnimal::getType	(void) const {

	return (this->_type);
}

void WrongAnimal::makeSound (void) const {

	std::cout << this->_type << ": Wrong Awoooo" << std::endl;
}
