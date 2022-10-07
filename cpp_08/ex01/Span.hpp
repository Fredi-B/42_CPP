#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <exception>

class Span
{
private:
	std::vector<int>	_storage;
	unsigned int		_maxSize;
	unsigned int		_currentSize;

public:
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span	&operator=(const Span &other);

	void	addNumber(int number);
	void	addManyNumbers(int amount);
	int		getNumber(int index) const;

	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	class	StorageFullException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class	NotEnoughStorageException : public std::exception
	{
	public:
		const char	*what() const throw();
	};

	class	NotEnoughEntriesException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
	
private:
	Span(void);
};

#endif
