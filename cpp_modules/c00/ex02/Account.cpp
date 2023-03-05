#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Account.hpp"

using std::cout;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_nbAccounts++;
	cout << "index:"   << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	_nbAccounts--;
	_totalAmount -= _amount;
	cout << "index:"	<< _accountIndex;
	cout << ";amount:"	<< _amount;
	cout << ";closed";
	if (_nbAccounts > 0)
		cout << std::endl;
}

/*	tm Time Struct (C++98):

	Member		|Type	|Meaning					|Range
	tm_sec		|int	|seconds after the minute	|0-61*
	tm_min		|int	|minutes after the hour		|0-59
	tm_hour		|int	|hours since midnight		|0-23
	tm_mday		|int	|day of the month			|1-31
	tm_mon		|int	|months since January		|0-11
	tm_year		|int	|years since 				|1900	
	tm_wday		|int	|days since Sunday			|0-6
	tm_yday		|int	|days since January 1		|0-365
	tm_isdst	|int	|Daylight Saving Time flag	|

	The Daylight Saving Time flag (tm_isdst) is greater than zero
	 if Daylight Saving Time is in effect, zero 
	 if Daylight Saving Time is not in effect, 
	 and less than zero if the information is not available.

	* tm_sec is generally 0-59. 
	The extra range is to accommodate for leap seconds in certain systems.
*/
void Account::_displayTimestamp(void)
{
	time_t rawtime;
	struct tm *timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	cout << "[";
	cout << timeinfo->tm_year + 1900;
	cout << std::setw(2) << std::setfill('0') << timeinfo->tm_mon + 1;
	cout << std::setw(2) << std::setfill('0') << timeinfo->tm_mday;
	cout << "_";
	cout << std::setw(2) << std::setfill('0') << timeinfo->tm_hour;
	cout << std::setw(2) << std::setfill('0') << timeinfo->tm_min;
	cout << std::setw(2) << std::setfill('0') << timeinfo->tm_sec;
	cout << "] ";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:"     << _nbAccounts;
	cout << ";total:"       << _totalAmount;
	cout << ";deposits:"    << _totalNbDeposits;
	cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" << _accountIndex;
	cout << ";amount:" << _amount;
	cout << ";deposits:" << _nbDeposits;
	cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	cout << "index:"		<< _accountIndex;
	cout << ";p_amount:"	<< _amount - deposit;
	cout << ";deposit:"		<< deposit;
	cout << ";amount:"		<< _amount;
	cout << ";nb_deposits:"	<< _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount < withdrawal)
	{
		cout << "index:"				<< _accountIndex;
		cout << ";p_amount:"			<< _amount;
		cout << ";withdrawal:refused"	<< std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	cout << "index:"			<< _accountIndex;
	cout << ";p_amount:"		<< _amount + withdrawal;
	cout << ";withdrawal:"		<< withdrawal;
	cout << ";amount:" 			<< _amount;
	cout << ";nb_withdrawals:"	<< _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
