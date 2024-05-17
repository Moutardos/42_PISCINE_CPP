#include "Cat.hpp"

Cat::Cat (void) : _brain(new Brain()) {

	std::cout << "Cat default constructor called" << std::endl;

	this->_type = "Cat";
};

Cat::Cat (Cat &cat) : _brain(new Brain()) {

	std::cout << "Cat copy constructor called" << std::endl;

	*this = cat;
}

Cat::~Cat (void) {

	std::cout << "Cat default destructor called" << std::endl;

	delete this->_brain;
}


Cat &Cat::operator=(Cat &c) {

	std::cout << "Cat copy operator called" << std::endl;

	this->_type = c._type;
	this->_brain->copy(c.getBrain());

	return (*this);
}

void Cat::makeSound (void) const {

	std::cout << this->_type << ": MIAOUU" << std::endl;
}

Brain &Cat::getBrain	(void) const {

	Brain &copy = *this->_brain;

	return (copy);
}

void	Cat::displayBrain(void) const {

	this->_brain->displayIdeas();
}

void	Cat::setIdea		(unsigned int n, const std::string &str) {

	this->_brain->setIdea(n, str);
}
