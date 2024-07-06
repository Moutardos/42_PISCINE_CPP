#ifndef PMERGEME
# define PMERGEME

# include <iostream>
# include <exception>
# include <list>
# include <vector>
# define ListTypePair std::list<CPair<Type> *>
# define ListType std::list<Type>

//container a utiliser liste?


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
			
			if (pos == 0 && _size > 0)
				return (static_cast<CPair<Type>*>(this->_left));
			if (pos == 1 && _size > 1)
				return (static_cast<CPair<Type>*>(this->_right));
			return (NULL);
		}
		Type	&operator*(void)
		{
			CPair	*curr;

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
				return(*b <**this);
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
			if (*static_cast<CPair<Type>*>(this->_right) < *static_cast<CPair<Type>*>(this->_left))
				std::swap(this->_left, this->_right);
		}

		int		getSize(void) const {

			return (_size);
		}
		static void	displayPair(CPair &pair) {

			if (pair.getSize() >= 2)
			{
				std::cout << "(";
				displayPair(*pair[0]);
			}
			else if (pair.getSize()== 1)
				std::cout << *pair;
			if (pair.getSize() >= 2)
			{
				std::cout << ",";
				displayPair(*pair[1]);
				std::cout << ")";
			}
		}
	private:
		void	*_left;
		void	*_right;
		int		_size;

};

//if the list is of size 1, return it. if not, pair the elements and
template <typename Type>
ListTypePair	mergeInsert(ListTypePair current)
{
	typename	ListTypePair			sortedPairs;
	typename	ListTypePair			finalList;
	bool								hasLeftOver = false;

	// for (typename ListTypePair::iterator itD = current.begin(); itD != current.end(); itD++)
	// {
	// 	CPair<Type>::displayPair(**itD);
	// 	std::cout << " ";
	// }
	// std::cout << "\n";
	// Creating the sorted pairs list
	if (current.size() == 1)
		return (current);
	sortedPairs = pairsPairs(nextList, hasLeftOver);
	
	finalList = mergeInsert(sortedPairs);
	Array<std::list<CPair*>::iterator, nextList.size()> 
	return (nextList);
}

template <typename Type>
ListTypePair	pairsPairs(ListTypePair pairs, bool &hasLeftover)
{
	typename	ListTypePair::iterator	it;
	typename	ListTypePair			sortedPairs;

	for (; it != pairs.end(); std::advance(it, 2))
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

// template <typename Type>
// ListTypePair	insert(ListTypePair sortedList, CPair pair)
// {

// }

template<class Iterator>
Iterator	next(Iterator it, int n = 1)
{
	std::advance(it, n);
	return (it);
}
int	jacob (unsigned int rank)
{
	int	value = 1 << rank;

	value -= ((rank % 2) + 1)/2 *-1;
	return (value / 3);
}
#endif