#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <iterator>
# include <stack>

template<typename T>
class	MutantStack : public std::stack<T> {

	public:

		class iterator {

			private:
				T* _it;
			
			public:
				iterator(void) : _it(NULL) {}
				iterator(T *ptr): _it(ptr) {}
				iterator(iterator const &ref): _it(ref._it){}
				iterator &operator=(iterator const &ref) {

					*this->_it = *ref;
				}
				~iterator(void) {}

				T	&operator*(void) {

					return (*_it);
				}

				iterator	operator++(void) {

					this->_it++;
					return (*this);
				}
				
				iterator	operator++(int) {

					iterator	tmp = *this;

					this->_it++;
					return (tmp);
				}
				iterator	operator--(void) {

					this->_it--;
					return (*this);
				}
				
				iterator	operator--(int) {

					iterator	tmp = *this;

					this->_it--;
					return (tmp);
				}

				bool	operator==(iterator &ref)
				{
					return (&*ref != this->_it);
				}
				bool	operator!=(iterator &ref)
				{
					return (&*ref != this->_it);
				}
		};

		MutantStack<T>(void) {};
		MutantStack<T>(MutantStack const &ref) {

			*this = ref;
		}
		MutantStack &operator=(MutantStack const &ref) {

			for (iterator it = ref.begin(); it != ref.end(); it++)
				this->c.push(*it);
			return (this);
		}
		~MutantStack(void) {}
		iterator	begin() {
		
			return (iterator(&this->c[0]));
		}
		iterator	end() {

			return (iterator((&this->c[0] + this->c.size())));
		}

};

#endif
