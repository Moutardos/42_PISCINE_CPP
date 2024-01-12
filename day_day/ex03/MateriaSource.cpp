
#include "MateriaSource.hpp"

MateriaSource::MateriaSource (void) {

	this->_emptySlot();
}

MateriaSource::MateriaSource	(MateriaSource &other) {

	*this = other;
}

MateriaSource::~MateriaSource	(void) {

	for (int i = 0; i < this->_slotSize; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
}

MateriaSource	&MateriaSource::operator= (MateriaSource &other) {

	other._copySlots(this->_slots);
	return (*this);
}

void MateriaSource::learnMateria (AMateria* m) {

	for (int i = 0; i < this->_slotSize; i++)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			return ;
		}
	}
	std::cout <<"Materia source slots are full" << std::endl;	
}

AMateria* MateriaSource::createMateria (std::string const & type) {

	AMateria	*materia = NULL;

	for (int i = 0; i < this->_slotSize; i++)
	{
		materia = this->_slots[i];
		if (materia != NULL)
		{
			if (materia->getType() == type)
				return (materia->clone());
		}
	}
	return (NULL);
}

void	MateriaSource::_emptySlot (void) {

	for (int i = 0; i < this->_slotSize; i++)
	{
		this->_slots[i] = NULL;
	}
}

void	MateriaSource::_copySlots (AMateria *slot[4]) {

	for (int i = 0; i < this->_slotSize; i++)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
			slot[i] = this->_slots[i]->clone();
		}
	}
}
