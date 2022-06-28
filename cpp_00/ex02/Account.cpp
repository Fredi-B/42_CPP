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
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}