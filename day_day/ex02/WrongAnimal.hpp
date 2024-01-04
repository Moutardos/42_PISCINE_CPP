#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

class WrongAnimal {

public:
	WrongAnimal	(void);
	WrongAnimal	(WrongAnimal &WrongAnimal);
	~WrongAnimal	(void);
	WrongAnimal	&operator=(WrongAnimal &c);

	std::string		getType	(void) const;
	void	makeSound (void) const;

protected:
	std::string _type;

};

#endif