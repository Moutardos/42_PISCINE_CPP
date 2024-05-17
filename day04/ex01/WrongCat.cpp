#include "WrongCat.hpp"

WrongCat::WrongCat (void) {

	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
};

WrongCat::WrongCat (WrongCat &WrongCat) {

	std::cout << "WrongCat copy constructor called" << std::endl;

	*this = WrongCat;
}

WrongCat::~WrongCat (void) {

	std::cout << "WrongCat default destructor called" << std::endl;
}


WrongCat &WrongCat::operator=(WrongCat &c) {

	std::cout << "WrongCat copy operator called" << std::endl;

	this->_type = c._type;
	
	return (*this);
}

void WrongCat::makeSound (void) const {

	std::cout << this->_type << ": WRONG MIAOUU" << std::endl;
}
