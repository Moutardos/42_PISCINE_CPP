#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

template<typename T>
class	Array : public std::exception {

	public:
		Array(): _size(0), _array(NULL) {}
		Array(Array const &ref) {
		
		*this = ref;
		}
		Array	&operator=(Array const &ref) {
			
			this->_array = new T[ref._size];
			for (unsigned int i = 0; i < ref._size; i++)
				this->_array[i] = ref._array[i];
			this->_size = ref._size;
			return (*this);
		}
		~Array() {
		
			delete[] _array;
		}
		Array(unsigned int n): _size(n), _array(new T[_size]) {}
		T		&operator[](unsigned int n) {
		
			if (n >= _size)
				throw std::out_of_range("Out of range element for array");
			return (this->_array[n]);
		}

		private:
			unsigned int	_size;
			T 				*_array;
};

#endif
