#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

class Animal {

public:
	Animal	(void);
	Animal	(Animal &animal);
	virtual ~Animal	(void);
	Animal	&operator=(Animal &c);

	std::string		getType	(void) const;
	virtual void	makeSound (void) const = 0;

protected:
	std::string _type;

};

#endif