#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	std::cout << "add timestamp" << "index:" << this->_nbAccounts << ";amount:" << this->_amount << ";created" << std::endl;
	this->_nbAccounts++;
	return;
}

Account::~Account(void)
{
	std::cout << "add timestamp" << "index:" << this->_nbAccounts << ";amount:" << this->_amount << ";closed" << std::endl;
	this->_nbAccounts--;
}
