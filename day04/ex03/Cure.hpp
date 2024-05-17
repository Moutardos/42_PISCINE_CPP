#ifndef CURE_H
# define CURE_H

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {

public:
	Cure	(void);
	Cure	(Cure &other);
	~Cure	(void);
	Cure	&operator= (Cure &other);
	void use(ICharacter& target);
	Cure* clone() const;

private:

};

#endif
