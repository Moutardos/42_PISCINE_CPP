#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain {

	public:
	Brain	(void);
	Brain	(Brain &brain);
	~Brain	(void);
	Brain	&operator=(Brain &c);


	private:
	std::string	ideas[100];
};
#endif