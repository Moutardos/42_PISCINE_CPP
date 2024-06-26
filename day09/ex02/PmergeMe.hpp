#ifndef PMERGEME
# define PMERGEME

# include <iostream>


//container a utiliser liste?


//	Cpair is a container-like class that contains in it's left or right member either another CPair
//	or a value of type Type. the accesor * shall return the valun of the left most value (error if it's NULL)
//  and [0] [1] accesor return the current left or right member.
//  The user shall provide it's own comp function for the CPair last value
template <typename Type>
class CPair {

	public:
		CPair	(void); {
			
			_left = NULL;
			_right = NULL;
			_size = 0;
		}
		CPair	(Pair *left, Pair *right, bool	(*comp)(Type const&, Type const&))
		{
			_left = left;
			_right = right;
			comp = comp;
			_size = left->size + right->size;
		};

		CPair	(CPair &ref)
		{
			ref = *this;
		}
		~CPair	(void) {}
		CPair	&operator=	(CPair &other) {
			//random norm bs

		}
		CPair	&operator[](bool pos)
		{
			if (pos == 0)
				return (*this->_left);
			if (pos == 1)
				return (*this->_right);
		}
		Type	&operator*(void)
		{
			CPair	*curr;
			curr = this;
			while (curr->_size > 1)
			{
				curr = this->left;
			}
			if (curr->_left == NULL)
				throw std::logic_error();
			return (this->_left);
		}

	private:
		void	*_left;
		void	*_right;
		bool	(*_comp)(Type const&, Type const&);
		int		_size;

};

#endif