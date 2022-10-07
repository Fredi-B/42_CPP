#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _maxSize(N), _currentSize(0) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span() {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_storage = other._storage;
		this->_maxSize = other._maxSize;
		this->_currentSize = other._currentSize;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_currentSize < this->_maxSize)
	{
		this->_storage.push_back(number);
		this->_currentSize++;
	}
	else
		throw StorageFullException();
}

int	randomGenerator(void)
{
	return (arc4random() % 100000000);
}

void	Span::addManyNumbers(int amount)
{
	if (this->_currentSize + amount <= this->_maxSize)
	{
		for (int i = 0; i < amount; i++)
		{
			this->_storage.push_back(randomGenerator());
		}
		this->_currentSize += amount;
	}
	else
		throw NotEnoughStorageException();
}

int	Span::getNumber(int index) const
{
	if (static_cast<unsigned int>(index) < this->_currentSize)
		return (this->_storage.at(index));
	return (-1);
}

int	Span::shortestSpan(void) const
{
	if (this->_currentSize < 2)
		throw NotEnoughEntriesException();

	int	shortest = INT32_MAX;
	std::vector<int>	copy = this->_storage;
	std::vector<int>::iterator		ite = copy.end();

	std::sort(copy.begin(), ite);
	for (std::vector<int>::iterator it = copy.begin(); it + 1 != ite; it++)
	{
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}

long long	Span::longestSpan(void) const
{
	if (this->_currentSize < 2)
		throw NotEnoughEntriesException();

	int	smallest =  *std::min_element(this->_storage.begin(), this->_storage.end());
	int	biggest = *std::max_element(this->_storage.begin(), this->_storage.end());
	return (biggest - smallest);
}

const char	*Span::StorageFullException::what() const throw()
{
	return ("Storage is full");
}

const char	*Span::NotEnoughStorageException::what() const throw()
{
	return ("Not enough storage left");
}

const char	*Span::NotEnoughEntriesException::what() const throw()
{
	return ("Not enough entries");
}
