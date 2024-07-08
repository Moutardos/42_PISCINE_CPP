#ifndef PMERGEME
# define PMERGEME

# include <iostream>
# include <exception>
# include <list>
# include <vector>
# define ListTypePair std::list<CPair<Type> *>
# define ListType std::list<Type>

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

template<typename Type>
void	displayListPair(ListTypePair list)
{
	std::cout << "[";
	for (typename	ListTypePair::iterator it = list.begin(); it != list.end(); it++)
	{
		CPair<Type>::displayPair(**it);
		if (::next(it) != list.end())
		std::cout << ", ";
	}
	std::cout << "]\n";
}
//if the list is of size 1, return it. if not, pair the elements and
template <typename Type>
ListTypePair	mergeInsert(ListTypePair current)
{
	typename	ListTypePair			sortedPairs;
	typename	ListTypePair			finalList;
	bool								hasLeftOver = false;

	std::cout << " |Entering MergeInsert|" << std::endl;
	// Creating the sorted pairs list
	if (current.size() == 1)
	{
		std::cout << "|Exiting MergeInsert, list is size 1|" << std::endl;
		return (current);
	}
	sortedPairs = pairsPairs(current, hasLeftOver);
	displayListPair(sortedPairs);
	finalList = mergeInsert(sortedPairs);

	std::cout << "  |Now inserting|" << std::endl;
	std::list<typename ListTypePair::iterator>	toTreat;
	typename ListTypePair::iterator	begin = finalList.begin();
	int	n = 1;
	while (begin != finalList.end())
	{
		int	diff = jacob(n + 1) - jacob(n);
		std::cout << "diff :" << diff << std::endl;
		if (static_cast<size_t>(std::distance(finalList.begin(), begin) + diff) > finalList.size())
		{
			diff = static_cast<size_t>(std::distance(finalList.end(), begin));
			std::cout << "too much !!!  diff now : " << diff << std::endl;
			begin = finalList.end();
		}
		else
			std::advance(begin, diff);
		typename ListTypePair::iterator	it = begin;
		for (int i = 0; i < diff; i++)
		{
			toTreat.push_back(it);
			std::advance(it, -1);
		}
	/*
		1 1 3 5
		-> 
		1 - 1 = 0 -> 0->0
		3 - 1 = 2 -> 2->1
		5 - 3 = 2 -> 4->3
		11 - 5 = 6 -> 10->5
		0,2,1,4,3,10,9,8,7,6,5
	*/	n++;
	}
	// for (typename std::list<typename ListTypePair::iterator>::iterator it = toTreat.begin(); it != toTreat.end(); it++)
	// {
	// 	CPair<Type>::displayPair(***it);
	// }
	std::cout << "|Exiting MergeInsert|" << std::endl;
	return (sortedPairs);
}

template <typename Type>
ListTypePair	pairsPairs(ListTypePair pairs, bool &hasLeftover)
{
	typename	ListTypePair			sortedPairs;

	for (typename	ListTypePair::iterator	it = pairs.begin(); it != pairs.end(); std::advance(it, 2))
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



#endif