#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

public:
	Cat	(void);
	Cat	(Cat &Cat);
	~Cat(void);
	Cat	&operator=(Cat &c);

	void	makeSound	(void) const;
	Brain	&getBrain	(void) const;
	void	displayBrain(void) const;
	void	setIdea		(unsigned int n, const std::string &str);
	
private:
	Brain	*_brain;

};

#endif