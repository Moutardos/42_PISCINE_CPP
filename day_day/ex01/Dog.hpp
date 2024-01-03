#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
class Dog : public Animal {

public:
	Dog	(void);
	Dog	(Dog &Dog);
	~Dog(void);
	Dog	&operator=(Dog &c);

	void	makeSound	(void) const;
private:

};

#endif