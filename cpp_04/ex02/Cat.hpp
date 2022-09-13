#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &other);
	~Cat(void);

	Cat	&operator=(const Cat &other);

	void	makeSound(void) const;
	Brain		*getBrain(void) const;
	void		setIdea(std::string idea, unsigned int i);
	std::string	getIdea(unsigned int i) const;

private:
	Brain	*brain;
};

#endif
