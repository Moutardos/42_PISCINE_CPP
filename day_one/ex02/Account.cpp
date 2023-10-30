#include "Account.hpp"
#include <ctime>
#include <iostream>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts),
		_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return;
}

Account::~Account( void ) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){

	return (_nbAccounts);
}

int	Account::getTotalAmount( void ){

	return (_totalAmount);
}

int	Account::getNbDeposits( void ){

	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ){

	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{

	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << 
	_totalNbDeposits << ";whithdrawls:" << _totalNbWithdrawals << std::endl;
	return ;
}

void	Account::makeDeposit( int deposit ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";deposit:";
	if (deposit > 0)
	{
		_totalNbDeposits++;
		_nbDeposits++;
		std::cout << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
		_amount += deposit;
		_totalAmount += deposit;
	}
	else
		std::cout << "refused" << std::endl;
}
bool	Account::makeWithdrawal( int withdrawal ) {

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > 0)
	{
		if (this->checkAmount() >= withdrawal)
		{
			_totalNbWithdrawals++;
			_nbWithdrawals++;
			std::cout << withdrawal << ";amount:" << this->_amount + withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			return (true);
		}
	}
	std::cout << "refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << 
	_nbDeposits << ";whithdrawals:" << _nbWithdrawals << std::endl;
}
void	Account::_displayTimestamp( void )
{
	std::time_t	time = std::time(nullptr);
	std::tm*	tm = std::localtime(&time);
	char str_date[20];

	std::strftime(str_date, 20, "[%Y%d%e_%H%M%S] ", tm);
	std::cout << str_date;
}
