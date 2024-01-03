#include "Cat.hpp"

Cat::Cat (void) {

	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
};

Cat::Cat (Cat &cat) {

	std::cout << "Cat copy constructor called" << std::endl;

	*this = cat;
}

Cat::~Cat (void) {

	std::cout << "Cat default destructor called" << std::endl;
}


Cat &Cat::operator=(Cat &c) {

	std::cout << "Cat copy operator called" << std::endl;

	this->_type = c._type;
	
	return (*this);
}

void Cat::makeSound (void) const {

	std::cout << this->_type << ": MIAOUU" << std::endl;
}
