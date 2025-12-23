#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm* local = std::localtime(&t);
	std::cout << "[" << local->tm_year + 1900 << local->tm_mon + 1 << local->tm_mday
				<< "_" << local->tm_hour + 1 << local->tm_min << local->tm_sec << "] " << std::endl;
}

Account::Account(int initial_deposit)
{
	Account::_amount = initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::cout;
}

bool Account::makeWithdrawal(int withdrawal)
{

}

int	Account::checkAmount(void) const
{

}

void Account::displayStatus(void) const
{

}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbDeposits);
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
				<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:"
				<< Account::getNbWithdrawals() << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
}