#ifndef CHARACTER_H
# define CHARACTER_H

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter {

public:
	Character	(void);
	Character	(Character &other);
	Character 	(const std::string &name);
	Character	&operator= (Character &other);
	~Character	(void);

	std::string const & getName	(void) const;
	void 				equip	(AMateria* m);
	void 				unequip	(int idx);
	void 				use		(int idx, ICharacter& target);

private:
	static const int	_invSize = 4;

	std::string _name;
	AMateria	*_inv[4];
	
	void	_emptyInv (void);
	void	_copyInv	(AMateria *inv[4]);

};

#endif
