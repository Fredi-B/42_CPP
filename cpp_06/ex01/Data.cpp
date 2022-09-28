#include "Data.hpp"

Data::Data() : name("emi"), age(26) {}

Data::Data(const Data &other)
{
	*this = other;
}

Data::~Data() {}

Data	&Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->age = other.age;
	}
	return (*this);
}
