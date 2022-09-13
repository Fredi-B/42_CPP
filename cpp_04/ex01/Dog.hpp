#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);

	Dog	&operator=(const Dog &other);

	void		makeSound(void) const;
	Brain		*getBrain(void) const;
	void		setIdea(std::string idea, unsigned int i);
	std::string	getIdea(unsigned int i) const;

private:
	Brain *brain;
};

#endif
