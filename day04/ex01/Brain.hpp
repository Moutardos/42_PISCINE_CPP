#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class Brain {

	public:
	Brain	(void);
	Brain	(Brain &brain);
	~Brain	(void);
	Brain	&operator=(Brain &c);

	void	displayIdeas (void) const;
	void	copy  (Brain &c);
	
	void		setIdea (unsigned int n, const std::string &idea);

	private:
	std::string	_ideas[100];

};
#endif