#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

public:
	Dog	(void);
	Dog	(Dog &Dog);
	~Dog(void);
	Dog	&operator=(Dog &c);

	void	makeSound	(void) const;
	Brain	&getBrain	(void) const;
	void	displayBrain(void) const;
	void	setIdea		(unsigned int n, const std::string &str);
	
private:
	Brain	*_brain;

};

#endif