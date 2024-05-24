#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *arr, unsigned int length, void (*f(T &)));

#endif