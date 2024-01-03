#include "Brain.hpp"

Brain::Brain	(void): {

	std::cout << "Brain default constructor called" << std::endl;
	_ideas[0] = "check blackholes days";
}

Brain::Brain	(Brain &brain) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain	(void) {

	std::cout << "Brain default deconstructor called" << std::endl;
}
Brain	&Brain::operator=(Brain &c) {

	std::cout << "Brain copy assignator called" << std::endl;

	this->ideas = ideas;
}
