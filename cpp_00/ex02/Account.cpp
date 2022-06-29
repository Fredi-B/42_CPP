#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << getNbAccounts()
				<< ";amount:" << checkAmount()
				<< ";created" << std::endl;
	_totalAmount += checkAmount();
	this->_accountIndex = getNbAccounts();
	_nbAccounts++;
	return;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";closed" << std::endl;
	_nbAccounts--;
}

int	Account::getNbAccounts(void) { return (_nbAccounts); }

int	Account::getTotalAmount(void){ return (_totalAmount); }

int	Account::getNbDeposits(void) { return (_totalNbDeposits); }

int	Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

int	Account::checkAmount(void) const { return (this->_amount); }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
				<< ";total:" << getTotalAmount()
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << checkAmount()
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex 
					<< ";p_amount:" << checkAmount()
					<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << checkAmount()
				<< ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";amount:" << checkAmount()
				<< ";nb_withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << checkAmount()
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);
	/* change format of month? */
	std::cout << "[" 
				<< now->tm_year + 1900
				<< std::setfill('0') << std::setw(2) << now->tm_mon + 1
				<< std::setfill('0') << std::setw(2) << now->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2) << now->tm_hour
				<< std::setfill('0') << std::setw(2) << now->tm_min
				<< std::setfill('0') << std::setw(2) << now->tm_sec
				<< "] ";
	// std::cout << "[19920104_091532] ";
}
