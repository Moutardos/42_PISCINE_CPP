#ifndef WRONGCAT_H
# define WRONGCAT_H

# include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {

public:
	WrongCat	(void);
	WrongCat	(WrongCat &WrongCat);
	~WrongCat(void);
	WrongCat	&operator=(WrongCat &c);

	void	makeSound	(void) const;
private:

};

#endif