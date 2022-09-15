#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->templates[i] = NULL;
	// std::cout << "MateriaSource constructed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
	// std::cout << "Copy of MateriaSource constructed" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] != NULL)
			delete this->templates[i];
	}
	// std::cout << "MateriaSource destructed" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] != NULL)
		{
			delete this->templates[i];
			this->templates[i] = NULL;
		}
		if (other.templates[i] != NULL)
			this->templates[i] = other.templates[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i] == NULL)
		{
			this->templates[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->templates[i]->getType() == type)
			return (this->templates[i]->clone());
	}
	return (NULL);
}
