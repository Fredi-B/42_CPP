#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T = int>
class Array
{
public:
	Array(void)
	{
		t_array = NULL;
		_size = 0;
	}

	Array(unsigned int n)
	{
		t_array = new T[n]();
		_size = n;
	}

	Array(const Array &other)
	{
		this->t_array = NULL;
		*this = other;
	}

	~Array()
	{
		if (t_array != NULL)
			delete[] t_array;
	}

	Array	&operator=(const Array &other)
	{
		if (this != &other)
		{
			if (this->t_array != NULL)
				delete[] this->t_array;
			if (other.size() > 0)
			{
				this->t_array = new T[other.size()];
				for (size_t i = 0; i < other.size(); i++)
					this->t_array[i] = other.t_array[i];
			}
			this->_size = other._size;
		}
		return (*this);
	}

	T	&operator[](unsigned int idx)
	{
		if (idx > this->_size || this->t_array == NULL)
			throw OutOfBoundException();
		return (this->t_array[idx]);
	}

	class OutOfBoundException : public std::exception
	{
	public:
		const char	*what() const throw()
		{
			return ("Index is out of bounds");
		}
	};

	size_t	size(void) const
	{
		return (this->_size);
	}

private:
	T		*t_array;
	size_t	_size;
};

#endif
