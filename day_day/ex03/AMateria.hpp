#ifndef AMATERIA_H
# define AMATERIA_H

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {

public:
	AMateria	(void);
	AMateria	(AMateria &other);
	virtual ~AMateria	(void);
	AMateria	&operator= (AMateria &other);

	AMateria (std::string const & type);
	std::string const &getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use (ICharacter& target);

protected:
	std::string	_type;

};

#endif
