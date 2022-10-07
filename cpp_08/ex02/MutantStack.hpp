#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator	iterator;

	MutantStack(void) {}
	MutantStack(const MutantStack &other) {*this = other;}
	~MutantStack(void) {}

	MutantStack	&operator=(const MutantStack &other)
	{
		if (this != &other)
			this->c = other.c;
		return (*this);
	}

	iterator	begin(void) {return (this->c.begin());}
	iterator	end(void) {return (this->c.end());}
};

#endif
