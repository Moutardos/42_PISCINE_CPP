#include "Brain.hpp"

Brain::Brain	(void) {

	std::cout << "Brain default constructor called" << std::endl;
	_ideas[0] = "check blackholes days";
}

Brain::Brain (Brain &brain) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain (void) {

	std::cout << "Brain default deconstructor called" << std::endl;
}
Brain &Brain::operator= (Brain &c) {

	std::cout << "Brain copy assignator called" << std::endl;
	
	this->copy(c);
	return (*this);
}

void Brain::copy (Brain &c) {

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = c._ideas[i].c_str();
}
void Brain::displayIdeas (void) const {
	
	for (int i = 0; i < 100; i++)
	{
		if (!this->_ideas[i].empty())
			std::cout << i << ": " << this->_ideas[i] << std::endl;
	}
}

void	Brain::setIdea (unsigned int n, const std::string &idea) {

	if (n < 100)
		this->_ideas[n] = idea.c_str();
}
