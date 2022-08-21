#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    //return (_nbAccounts);
}


void	Account::makeDeposit( int deposit )
{
    _amount += deposit;
    _nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal)
{
    if (_amount - withdrawal < 0)
    {
        std::cout << "refused\n";
        return (1);
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    return (0);
}

int 		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus(void ) const
{
    //return (_amount);
}

static void	_displayTimestamp( void )
{
    std::cout << "[testtime]";
}

Account::~Account( void )
{
    std::cout << "[destroyed]";

}

