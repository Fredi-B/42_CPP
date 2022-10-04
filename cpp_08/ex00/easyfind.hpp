#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include <list>
# include <stack>


class notFoundException : public std::exception
{
public:
	const char	*what() const throw()
	{
		return ("Integer not found");
	}
};

template<typename T>
int	easyfind(T &t, int i)
{
	typename T::const_iterator	it;

	it = std::find(t.begin(), t.end(), i);
	if (it == t.end())
		throw notFoundException();
	return (*it);
}

#endif
