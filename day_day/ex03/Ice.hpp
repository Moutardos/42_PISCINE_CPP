#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria {

public:
	Ice	(void);
	Ice	(Ice &other);
	~Ice	(void);
	Ice	&operator= (Ice &other);
	void use(ICharacter& target);
	Ice* clone() const;

private:

};

#endif
