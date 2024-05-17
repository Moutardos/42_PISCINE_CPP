#include "Dog.hpp"

Dog::Dog (void) : _brain(new Brain())  {

	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
};

Dog::Dog (Dog &Dog) : _brain(new Brain())  {

	std::cout << "Dog copy constructor called" << std::endl;

	*this = Dog;
}

Dog::~Dog (void) {

	std::cout << "Dog default destructor called" << std::endl;

	delete this->_brain;
}


Dog &Dog::operator=(Dog &c) {

	std::cout << "Dog copy operator called" << std::endl;

	this->_type = c._type;
	this->_brain->copy(c.getBrain());

	return (*this);
}

void Dog::makeSound (void) const {

	std::cout << this->_type << ": AWOOOOOF" << std::endl;
}

Brain &Dog::getBrain	(void) const {

	Brain &copy = *this->_brain;

	return (copy);
}

void	Dog::displayBrain(void) const {

	this->_brain->displayIdeas();
}

void	Dog::setIdea		(unsigned int n, const std::string &str) {

	this->_brain->setIdea(n, str);
}