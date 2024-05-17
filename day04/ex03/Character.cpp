#include "Character.hpp"

Character::Character	(void) : _name("Unnamed") {

	this->_emptyInv();
}

Character::Character	(Character &other) {

	this->_emptyInv();
	*this = other;
}

Character::~Character	(void) {

	for (int i = 0; i < this->_invSize; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
}
ICharacter::~ICharacter	(void) {}

Character	&Character::operator= (Character &other)
{
	this->_name = other._name;
	other._copyInv(this->_inv);
	return (*this);
}

Character::Character (const std::string &name) : _name(name) {

	this->_emptyInv();
};

std::string const &Character::getName (void) const {

	return (this->_name);
}

void Character::equip(AMateria* m) {

	if (!m)
		return ;
	for (unsigned int i = 0; i < this->_invSize; i++)
	{
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = m;
			return ;
		}
	}
	std::cout << this->_name << ": inventory is full" << std::endl;	
}

void Character::unequip(int idx) {

	if (idx >= 0 && idx < this->_invSize)
		this->_inv[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {

	AMateria	*materia;

	if (idx >= 0 && idx < this->_invSize)
	{
		materia = this->_inv[idx];
		if (materia)
			materia->use(target);
	}
}

void	Character::_emptyInv (void) {

	for (int i = 0; i < this->_invSize; i++)
		this->_inv[i] = NULL;
}

void	Character::_copyInv (AMateria *inv[4]) {

	for (int i = 0; i < this->_invSize; i++)
	{
		if (inv[i] != NULL)
		{
			delete inv[i];
			inv[i] = this->_inv[i]->clone();
		}
	}
}
