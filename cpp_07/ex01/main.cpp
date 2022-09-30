#include "iter.hpp"

int	main(void)
{
	int		i[3] = {1, 2, 3};
	float	f[3] = {1.1, 2.2, 3.3};
	char	c[3] = {'a', 'b', 'c'};
	std::string	s[3] = {"s1", "s2", "s3"};

	iter(i, 3, &fct);
	iter(f, 3, &fct);
	iter(c, 3, &fct);
	iter(s, 3, &fct);

	return (0);
}
