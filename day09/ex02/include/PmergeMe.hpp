#ifndef PMERGEME
# define PMERGEME

# include <algorithm>
# include <iostream>
# include <exception>
# include <list>
# include <vector>
# include <memory>

# include "logger.hpp"
# include "color.hpp"

# define ContainerCPair Container<CPair<Type> *, Allocator>

int compCount = 0;
// JacobSthal for rank
int	jacob(unsigned int rank)
{
	int	value = 1 << rank;
	value -= ((rank % 2) + 1)/2 * -1;
	return (value / 3);
}

template<class Iterator>
Iterator	next(Iterator it, int n = 1)
{
	std::advance(it, n);
	return (it);
}

//	Cpair is a container-like class that contains in it's left or right member either another CPair
//	or a value of type Type. the accesor * shall return the valun of the left most value (error if it's NULL)
//  and [0] [1] accesor return the current left or right member.
template <typename Type>
class CPair {

	public:
		CPair	(void) {

			_left = NULL;
			_right = NULL;
			_size = 0;
		}
		CPair	(CPair *left, CPair *right)
		{
			_left = left;
			_right = right;
			_size = left->getSize() + right->getSize();
		}
		CPair	(Type &left)
		{
			_left = &left;
			_right = NULL;
			_size = 1;
		}
		CPair	(CPair &ref)
		{
			(void) ref;
			// ref = *this;
		}
		~CPair	(void) {}
		CPair	&operator=	(CPair &other) {
			//random norm bs
			(void) other;
	
		}
		CPair	*operator[](bool pos) 
		{
			
			if (pos == 0 && this->_size > 0)
				return (static_cast<CPair<Type>*>(this->_left));
			if (pos == 1 && this->_size > 1)
				return (static_cast<CPair<Type>*>(this->_right));
			return (NULL);
		}

		const CPair	*operator[](bool pos) const
		{
			
			if (pos == 0 && this->_size > 0)
				return (static_cast<CPair<Type>*>(this->_left));
			if (pos == 1 && this->_size > 1)
				return (static_cast<CPair<Type>*>(this->_right));
			return (NULL);
		}

		Type	&operator*(void) const
		{
			const CPair	*curr;

			curr = this;
			while (curr && curr->_size > 1)
			{
				curr = (*curr)[0];
			}
			if ((*curr)[0] == NULL)
				throw std::logic_error("Can't access to left member, it's NULL");
			return (*static_cast<int*>(curr->_left));
		}

		bool	operator<(CPair& b)
		{
			try
			{
				compCount++;
				LOG_CMP("comp between: " << **this << " and " << *b << std::endl); 
				return(**this <*b);
			}
			catch(const std::exception& e)
			{
				std::cerr << "One of the pair left value is null" << std::endl;
				return (false);
			}
			
		}
		void	sort(void)
		{
			if (!this->_right || !this->_left)
				return;
			if (*static_cast<CPair<Type>*>(this->_left) < *static_cast<CPair<Type>*>(this->_right))
				std::swap(this->_left, this->_right);
		}

		int		getSize(void) const {

			return (_size);
		}
		void	setRightPairNull(void)
		{
			this->_size -= static_cast<CPair<Type>*>(this->_right)->getSize();
			this->_right = NULL;
		}

	private:
		void	*_left;
		void	*_right;
		int		_size;

};

template <typename Type>
std::ostream	&operator<< (std::ostream &os, const CPair<Type> &pair)
{
	if (pair.getSize() >= 2)
	{
		os << "(";
		os << (*pair[0]);
	}
	else if (pair.getSize()== 1)
		os << *pair;
	if (pair.getSize() >= 2)
	{
		os << ",";
		os << (*pair[1]);
		os << ")";
	}
	return (os);
}	

template	<template <typename, typename> class Container,
			 typename Type,
         	 typename Allocator=std::allocator<CPair<Type> *> >
void	displayListPair(ContainerCPair list, bool endl=true)
{
	LOG_DEBUG("[");
	for (typename	ContainerCPair::iterator it = list.begin(); it != list.end(); it++)
	{
		LOG_DEBUG(**it);
		if (::next(it) != list.end())
			LOG_DEBUG(", ");
	}
	LOG_DEBUG("]");
	if (endl)
		LOG_DEBUG(std::endl);
}

template <typename Type>
bool	compPair(CPair<Type> *pair1, CPair<Type> *pair2)
{
	return (*pair1 < *pair2);
}
template	<template <typename, typename> class Container,
			 typename Type,
         	 typename Allocator=std::allocator<CPair<Type> *> >
ContainerCPair	insert(ContainerCPair upperMain, CPair<Type> *leftover = NULL)
{
	ContainerCPair			main;
	typename ContainerCPair::iterator	itStart = upperMain.begin();
	CPair<Type>						*toInsert;
	typename ContainerCPair::iterator	itRestart;
	bool							stop = false;

	int	n = 2;

	for (typename ContainerCPair::iterator it = upperMain.begin(); it != upperMain.end(); it++)
		main.push_back((*(*it))[0]);
	if (leftover)
	{
		upperMain.push_back(leftover);
	}
	LOG_DEBUG("Main chain: ");
	displayListPair(main);
	LOG_DEBUG("we insert the right element of the first pair at the beginning : ");
	main.push_front((*(*upperMain.begin()))[1]);
	displayListPair(main);
	while (itStart != upperMain.end())
	{
		int	diff = jacob(n + 1) - jacob(n) ;
		if (diff != 0)
		{
			if (static_cast<size_t>(std::distance(upperMain.begin(), itStart) + diff) >= upperMain.size())
			{
				diff = static_cast<size_t>(std::distance(itStart, upperMain.end()) - 1);
				itStart = ::next(upperMain.end(), -1);
				stop = true;
			}
			else
				std::advance(itStart, diff);
			itRestart = itStart;
			for (; diff > 0; diff--)
			{
				typename ContainerCPair::iterator itStop = main.begin();

				while (itStop != main.end() && (*(*itStart))[0] != *itStop)
				{
					itStop++;
				}
				if (itStop == main.end())
				{
					toInsert = *itStart;
				}
				else
					toInsert = (*(*itStart))[1];
				LOG_DEBUG("inserting: ");
				LOG_DEBUG(*toInsert);
				LOG_DEBUG(" into ");
				displayListPair(main);
				LOG_DEBUG(" stopping at : ");
				if (itStop == main.end())
					LOG_DEBUG("end of containers" << std::endl);
				else
					LOG_DEBUG(**itStop << " because " << **itStart<< std::endl);
				main.insert(std::upper_bound(main.begin(), itStop, toInsert, compPair<Type>),
					toInsert);
				std::advance(itStart, -1);
			}
		}
		itStart = itRestart;
		n++;
		if (stop)
			break;
	}
	return (main);
}
//if the list is of size 1, return it. if not, pair the elements and
template	<template <typename, typename> class Container,
			 typename Type,
         	 typename Allocator=std::allocator<CPair<Type> *> >
ContainerCPair	mergeInsert(ContainerCPair current)
{
	ContainerCPair			sortedPairs;
	ContainerCPair			main;
	bool								hasLeftOver = false;
	CPair<Type>							*leftover = NULL;

	LOG_DEBUG (" |Entering MergeInsert with ");
	displayListPair(current, false);
	LOG_DEBUG (" |" << std::endl);
	// Creating the sorted pairs list
	if (current.size() == 1)
	{
		LOG_DEBUG("|Exiting MergeInsert, list is size 1|" << std::endl);
		return (current);
	}
	sortedPairs = pairsPairs(current, hasLeftOver);
	if (hasLeftOver)
		leftover =  *(::next(current.end(), -1));
	LOG_DEBUG("Paired list is now : ");
	displayListPair(sortedPairs);
	sortedPairs = mergeInsert(sortedPairs);
	LOG_DEBUG("  |Now inserting|" << std::endl);

	displayListPair(sortedPairs);
	main = insert(sortedPairs, leftover);
	LOG_DEBUG("after insert : ->" << std::endl);
	displayListPair(main);
	for (typename ContainerCPair::iterator it = sortedPairs.begin(); it != sortedPairs.end(); it++)
		delete *it;
	LOG_DEBUG("|Exiting MergeInsert|" << std::endl);
	return (main);
}

template	<template <typename, typename> class Container,
			 typename Type,
         	 typename Allocator=std::allocator<CPair<Type> *> >
ContainerCPair	pairsPairs(ContainerCPair pairs, bool &hasLeftover)
{
	ContainerCPair	sortedPairs;

	for (typename	ContainerCPair::iterator	it = pairs.begin(); it != pairs.end(); std::advance(it, 2))
	{
		if (::next(it) == pairs.end())
		{
			hasLeftover = true;
			break;
		}
		CPair<Type>	*pair = new CPair<Type>(*it, *::next(it));
		pair->sort();
		sortedPairs.push_back(pair);
	}
	return (sortedPairs);
}

template	<template <typename, typename> class Container,
			 typename Type,
         	 typename Allocator=std::allocator<CPair<Type> *> > 
void	mergeInsertSort(std::list<int> list, bool print=false)
{
	ContainerCPair	pairContenair;
	ContainerCPair	main;
	if (print)
	{
		std::cout << "Before: ";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		{
			if (it != list.begin())
				std::cout << " ";
			std::cout << *it;
		}
		std::cout << std::endl;
	}

	compCount = 0;

	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		pairContenair.push_back(new CPair<Type>(*it));
	}
	main = mergeInsert<Container, Type>(pairContenair);
	if (print)
	{
		std::cout << "After: ";
		for (typename ContainerCPair::iterator it = main.begin(); it != main.end(); it++)
		{
			if (it != main.begin())
				std::cout << " ";
			std::cout << **it;
		}
		std::cout << std::endl;
	}
	for (typename ContainerCPair::iterator it = pairContenair.begin(); it != pairContenair.end(); it++)
		delete *it;

}



#endif