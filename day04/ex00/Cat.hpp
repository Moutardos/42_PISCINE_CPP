#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
class Cat : public Animal {

public:
	Cat	(void);
	Cat	(Cat &Cat);
	~Cat(void);
	Cat	&operator=(Cat &c);

	void	makeSound	(void) const;
private:

};

#endif