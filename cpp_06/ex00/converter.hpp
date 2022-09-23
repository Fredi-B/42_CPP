	class NotAScalarTypeException : public std::exception
	{
	public:
		const char	*what() const throw();
	};
