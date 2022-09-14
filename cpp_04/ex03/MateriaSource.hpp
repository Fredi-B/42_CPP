#ifndef CHARACTERSOURCE_HPP
# define CHARACTERSOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &other);

	void		learnMateria(AMateria *m);
	AMateria	*createMateria(std::string const &type);

private:
	AMateria	*templates[4];
};

#endif
