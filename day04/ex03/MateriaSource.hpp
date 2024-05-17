#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:
	MateriaSource	(void);
	MateriaSource	(MateriaSource &other);
	~MateriaSource	(void);
	MateriaSource	&operator=	(MateriaSource &other);

	void		learnMateria	(AMateria* m);
	AMateria*	createMateria	(std::string const & type);

private:
	static const int	_slotSize = 4;
	AMateria	*_slots[4];

	void	_emptySlot (void);
	void	_copySlots		(AMateria	*_slots[4]);
};

#endif
