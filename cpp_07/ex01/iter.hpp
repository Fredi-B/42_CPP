#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	fct(T &t)
{
	std::cout << t << std::endl;
}

template<typename T>
void	iter(T *t_array, size_t N, void (*fct)(T &))
{
	if (t_array == NULL && fct == NULL)
		return ;
	for (size_t i = 0; i < N; i++)
		fct(t_array[i]);
}

#endif
